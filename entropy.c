/*
** @author: Copyright (C) Francois Eichinger
** HEPIA 2018
** This program is free software, you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
	FILE* f = fopen("file.txt", "r");
	assert(f);
	int fileSize = file_size(f);
	int frequency = 0;
	int N = 0;
	float maxEntropy = 0;
	float sourceEntropy = 0.0;
	float redundance = 0.0;
	char* data = malloc(sizeof(char)*(fileSize + 1)); // + 1 = end char
	assert(data);
	int* count = malloc(sizeof(int)*(26));	//Char frequency array
	assert(count);
	float* hs = malloc(sizeof(float)*26);	//Source entropy array
	assert(hs);

	for (int i = 0; i < fileSize; i++)
	{
		count[i] = 0;
	}

	fread(data, 1, fileSize - 1, f);
	int freq = findFrequency(data, count, frequency);

   	printf("Character Count : \n");
	for (int i = 0; i < 26; i++)
	{
		if(count[i] != 0)
		{
			N++;
		}
		printf("%c = %d\n",(i + 97), count[i]);
	}
	for (int i = 0; i < 26; i++)
	{
		hs[i] = (((float)count[i])/freq);
	}

	for (int i = 0; i < 26; i++)
	{
		if(hs[i] == 0.0)
		{
			continue;
		}
		sourceEntropy += (-log(hs[i])/log(2))*hs[i];
	}
	maxEntropy = (log(N)/log(2));
	redundance = (maxEntropy-sourceEntropy)/sourceEntropy;

	printf("Char Total : %d char\n", freq);
	printf("Source entropy: %f\n", sourceEntropy);
	printf("Maximum entropy: %f\n", maxEntropy);
	printf("Redundancy rate: %F\n", redundance);

	free(hs);
	free(data);
	free(count);

	return 0;
}

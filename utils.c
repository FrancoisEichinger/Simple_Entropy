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

#include "utils.h"

long int file_size(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "Error in file_size : ");
        fprintf(stderr, "file is not initialized\n");
        return -1;
    }

    if (fseek(file, 0, SEEK_END) < 0) {
        fprintf(stderr, "Error in file_size : ");
        fprintf(stderr, "Something went wrong while getting the end of the file\n");
        return -1;
    }

    //Limited by the ftell output
    long int size = ftell(file);

    if (fseek(file, 0, SEEK_SET) < 0) {
        fprintf(stderr, "Error in file_size : ");
        fprintf(stderr, "Something went wrong while going back at the beggining of the file\n");
        return -1;
    }

    return size;
}

int findFrequency(char* data, int* count, int frequency)
{
	int i = 0;

	while (data[i] != '\0')
	{
	   /* If the current character is lowercase alphabet */
	   if(data[i]>='a' && data[i]<='z')
	   {
		   count[data[i] - 97]++;
           frequency++;
	   }
	   else if(data[i]>='A' && data[i]<='Z')
	   {
		   count[data[i] - 65]++;
           frequency++;
	   }
	   i++;
	}
    return frequency;
}

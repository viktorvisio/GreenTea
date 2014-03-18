/*
Copyright (C) 2014  Martin Kuzma

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MACROS_H_
#define MACROS_H_

#define FOR_RANGE(A, B) for(int n = A; n < B; n++)
#define FOR(FROM,TO,NAME) for(int NAME = FROM; NAME < TO; NAME++)
#define PRINT_ERROR(MSG)	printf("\033[1;31m[Error] %s:%d \t%s\033[0m\n", __FILE__,__LINE__, MSG);

#define	SWAP(A,B)	{A ^= B; B ^= A; A ^= B;}

#endif /* MACROS_H_ */

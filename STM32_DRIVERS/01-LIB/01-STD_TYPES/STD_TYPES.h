/*
 * STD_TYPES.h
 *
 *  Created on: June 09, 2023
 *      Author: Mohamed Tarek
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL_PTR	(void *)0

typedef unsigned char				u8;
typedef signed char					s8;
typedef unsigned short int			u16;
typedef signed short int			s16;
typedef unsigned long int			u32;
typedef signed long int				s32;
typedef unsigned long long int		u64;
typedef signed long long int		s64;
typedef float						f32;
typedef double						f64;
typedef long double					f128;

typedef enum {
	FALSE,
	TRUE
} BooleanType;


#endif /* STD_TYPES_H_ */
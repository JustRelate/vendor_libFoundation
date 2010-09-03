/* 
   NSValue.h

   Copyright (C) 1995, 1996 Ovidiu Predescu and Mircea Oancea.
   All rights reserved.

   Author: Mircea Oancea <mircea@jupiter.elcom.pub.ro>

   This file is part of libFoundation.

   Permission to use, copy, modify, and distribute this software and its
   documentation for any purpose and without fee is hereby granted, provided
   that the above copyright notice appear in all copies and that both that
   copyright notice and this permission notice appear in supporting
   documentation.

   We disclaim all warranties with regard to this software, including all
   implied warranties of merchantability and fitness, in no event shall
   we be liable for any special, indirect or consequential damages or any
   damages whatsoever resulting from loss of use, data or profits, whether in
   an action of contract, negligence or other tortious action, arising out of
   or in connection with the use or performance of this software.
*/

#ifndef __NSValue_h__
#define __NSValue_h__

#include <Foundation/NSObject.h>
#include <Foundation/NSGeometry.h>

@class NSString;
@class NSDictionary;

@interface NSValue : NSObject

// Internal method to determine concrete value class

+ (Class)concreteClassForObjCType:(const char*)type;

// Allocating and Initializing Value Objects

+ (NSValue*)valueWithBytes:(const void*)value objCType:(const char*)type;
+ (NSValue*)value:(const void*)value withObjCType:(const char*)type;
+ (NSValue*)valueWithNonretainedObject:(id)anObject;
+ (NSValue*)valueWithPointer:(const void*)pointer;

// Allocating and Initializing Geometry Value Objects

+ (NSValue*)valueWithPoint:(NSPoint)point;
+ (NSValue*)valueWithRect:(NSRect)rect;
+ (NSValue*)valueWithSize:(NSSize)size;

// Initializing
- (id)initWithBytes:(const void*)value objCType:(const char*)type;

// Accessing Data in Value Objects

- (void)getValue:(void*)value;
- (const char*)objCType;

- (id)nonretainedObjectValue;
- (void*)pointerValue;
- (void*)valueBytes;
- (BOOL)isEqualToValue:(NSValue*)aValue;

// Accessing Data in Geometry Value Objects

- (NSRect)rectValue;
- (NSSize)sizeValue;
- (NSPoint)pointValue;

@end

@interface NSNumber : NSValue

// Internal method to determine concrete value class

+ (Class)concreteClassForObjCType:(const char*)type;

// Allocating and Initializing

- (id)initWithBool:(BOOL)value;
- (id)initWithChar:(char)value;
- (id)initWithUnsignedChar:(unsigned char)value;
- (id)initWithShort:(short)value;
- (id)initWithUnsignedShort:(unsigned short)value;
- (id)initWithInt:(int)value;
- (id)initWithUnsignedInt:(unsigned int)value;
- (id)initWithLong:(long)value;
- (id)initWithUnsignedLong:(unsigned long)value;
- (id)initWithLongLong:(long long)value;
- (id)initWithUnsignedLongLong:(unsigned long long)value;
- (id)initWithFloat:(float)value;
- (id)initWithDouble:(double)value;

+ (NSNumber*)numberWithBool:(BOOL)value; 
+ (NSNumber*)numberWithChar:(char)value;
+ (NSNumber*)numberWithUnsignedChar:(unsigned char)value;
+ (NSNumber*)numberWithShort:(short)value;
+ (NSNumber*)numberWithUnsignedShort:(unsigned short)value;
+ (NSNumber*)numberWithInt:(int)value;
+ (NSNumber*)numberWithUnsignedInt:(unsigned int)value;
+ (NSNumber*)numberWithLong:(long)value;
+ (NSNumber*)numberWithUnsignedLong:(unsigned long)value;
+ (NSNumber*)numberWithLongLong:(long long)value;
+ (NSNumber*)numberWithUnsignedLongLong:(unsigned long long)value;
+ (NSNumber*)numberWithFloat:(float)value;
+ (NSNumber*)numberWithDouble:(double)value;

// Accessing Data 

- (BOOL)boolValue;
- (char)charValue;
- (unsigned char)unsignedCharValue;
- (short)shortValue;
- (unsigned short)unsignedShortValue;
- (int)intValue;
- (unsigned int)unsignedIntValue;
- (long)longValue;
- (unsigned long)unsignedLongValue;
- (long long)longLongValue;
- (unsigned long long)unsignedLongLongValue;
- (float)floatValue;
- (double)doubleValue;

// Converting to string

- (NSString*)stringValue;
- (NSString*)descriptionWithLocale:(NSDictionary*)locale;
- (NSString*)description;

// Comparing Data 

- (NSComparisonResult)compare:(NSNumber*)otherNumber;
- (BOOL)isEqualToNumber:(NSNumber*)aNumber;

@end

// Method to determine the conversion sense for comparing NSNumber values 

@interface NSNumber(Generality)
- (int)generality;
@end

#endif /* __NSValue_h__ */

/*
  Local Variables:
  c-basic-offset: 4
  tab-width: 8
  End:
*/

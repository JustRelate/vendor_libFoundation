/* 
   NSDateFormatter.h

   Copyright (C) 1998 MDlink online service center, Helge Hess
   All rights reserved.

   Author: Helge Hess (helge@mdlink.de)

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
// $Id: NSDateFormatter.h,v 1.1.1.1 2002/05/22 12:46:24 helge Exp $

#ifndef __NSDateFormatter_h__
#define __NSDateFormatter_h__

#include <Foundation/NSFormatter.h>

@class NSDate, NSCalendarDate;

@interface NSDateFormatter : NSFormatter < NSCopying, NSCoding >
{
  NSString *format;
  BOOL     allowsNaturalLanguage;
}

- (id)initWithDateFormat:(NSString *)_format allowNaturalLanguage:(BOOL)_flag;

- (NSString *)dateFormat;
- (BOOL)allowsNaturalLanguage;

@end

#endif

/*
  Local Variables:
  c-basic-offset: 4
  tab-width: 8
  End:
*/

/* ----------------------------- MNI Header -----------------------------------
@NAME       : string_to_filename.c
@DESCRIPTION: Code to convert a string to something that can be used in a 
              file name.
@METHOD     : 
@GLOBALS    : 
@CALLS      : 
@CREATED    : December 10, 1993 (Peter Neelin)
@MODIFIED   : 
 * $Log: string_to_filename.c,v $
 * Revision 6.2  2001-04-09 23:02:52  neelin
 * Modified copyright notice, removing permission statement since copying,
 * etc. is probably not permitted by our non-disclosure agreement with
 * Philips.
 *
 * Revision 6.1  1999/10/29 17:52:05  neelin
 * Fixed Log keyword
 *
 * Revision 6.0  1997/09/12 13:23:50  neelin
 * Release of minc version 0.6
 *
 * Revision 5.0  1997/08/21  13:24:50  neelin
 * Release of minc version 0.5
 *
 * Revision 4.0  1997/05/07  20:01:07  neelin
 * Release of minc version 0.4
 *
 * Revision 3.0  1995/05/15  19:31:44  neelin
 * Release of minc version 0.3
 *
 * Revision 2.0  1994/09/28  10:35:36  neelin
 * Release of minc version 0.2
 *
 * Revision 1.2  94/09/28  10:35:05  neelin
 * Pre-release
 * 
 * Revision 1.1  93/12/10  15:35:18  neelin
 * Initial revision
 * 
@COPYRIGHT  :
              Copyright 1993 Peter Neelin, McConnell Brain Imaging Centre, 
              Montreal Neurological Institute, McGill University.
---------------------------------------------------------------------------- */

#include <gcomserver.h>
#include <ctype.h>

#define SEPARATOR '_'

/* ----------------------------- MNI Header -----------------------------------
@NAME       : string_to_filename
@INPUT      : string - string to convert
              maxlen - maximum length of output string (including terminating
                 '\0')
@OUTPUT     : filename - output string
@RETURNS    : (nothing)
@DESCRIPTION: Routine to convert a string to something that can be used in
              a filename
@METHOD     : 
@GLOBALS    : 
@CALLS      : 
@CREATED    : December 10, 1993 (Peter Neelin)
@MODIFIED   : 
---------------------------------------------------------------------------- */
public void string_to_filename(char *string, char *filename, int maxlen)
{
   int length, isrc, idst;
   int ch;
   int found_first, need_separator;

   /* Get string length */
   length = strlen(string);
   if (length > maxlen-1) length = maxlen - 1;

   /* Loop through characters */
   idst = 0;
   found_first = FALSE;
   need_separator = FALSE;
   for (isrc=0; isrc < length; isrc++) {
      ch = string[isrc];
      if (isalnum(ch)) {
         found_first = TRUE;
         if (need_separator) {
            filename[idst++] = SEPARATOR;
            need_separator = FALSE;
         }
         filename[idst++] = tolower(ch);
      }
      else if (found_first) {
         need_separator = TRUE;
      }
   }

   /* Add terminating '\0' */
   filename[idst++] = '\0';

   return;
}


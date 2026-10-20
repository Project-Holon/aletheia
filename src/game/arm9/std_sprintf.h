#ifndef GAME_ARM9_STD_SPRINTF_H
#define GAME_ARM9_STD_SPRINTF_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of std_sprintf.c, prototypes copied from their definitions. */

struct dst_string_tag;

void string_put_char(struct dst_string_tag *p, char c);
void string_fill_char(struct dst_string_tag *p, char c, int n);
void string_put_string(struct dst_string_tag *p, const char *s, int n);
int STD_TSPrintf(char *dst, const char *fmt, ...);
int STD_TSNPrintf(char *dst, int n, const char *fmt, ...);
/* END mkheaders: generated region */

#endif

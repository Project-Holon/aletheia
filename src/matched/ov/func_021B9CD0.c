/*
 * function: func_021B9CD0
 * address:  0x021B9CD0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks the 0x30 records of 0x1C bytes at +0x30 and calls the handler stored
 * at +0x48 of each occupied one with (p, record).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

void func_021B9CD0(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32 *)(p + i * 0x1C + 0x30) != 0) {
            void (*f)(char *, char *) = *(void (**)(char *, char *))(p + i * 0x1C + 0x48);

            f(p, p + 0x30 + i * 0x1C);
        }
    }
}

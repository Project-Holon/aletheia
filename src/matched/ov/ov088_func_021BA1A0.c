/*
 * function: func_021BA1A0
 * address:  0x021BA1A0
 * packet:   pkt_ov088_021BA1A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D210  0x0203D210  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_021BA9C8  0x021BA9C8  thumb  ov088
 *   func_021BAC64  0x021BAC64  thumb  ov088
 *   func_021BB474  0x021BB474  thumb  ov088
 *   func_021BB328  0x021BB328  thumb  ov088
 *   func_021BB164  0x021BB164  thumb  ov088
 *   func_021BB5C4  0x021BB5C4  thumb  ov088
 *   func_021BACD8  0x021BACD8  thumb  ov088
 *   func_021BAB20  0x021BAB20  thumb  ov088
 */

typedef unsigned int   u32;
extern u32 func_0203D210(void);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_021BA9C8(void *);
extern void func_021BAC64(char *p);
extern void func_021BB474(char *p);
extern void func_021BB328(char *p);
extern void func_021BB164(char *p);
extern void func_021BB5C4(char *p);
extern void func_021BACD8(void *);
extern void func_021BAB20(void);

int func_021BA1A0(char *p)
{
    unsigned s;
    s = *(unsigned char *)(p + 0x12a);
    switch (s) {
    case 0:
        *(unsigned char *)(p + 0x12a) = s + 1;
    case 1:
        if (func_0203D210() != 0) {
            func_021BA9C8(p);
            func_021BAC64(p);
            func_021BB474(p);
            func_021BB328(p);
            func_021BB164(p);
            func_021BB5C4(p);
            func_021BACD8(p);
            func_021BAB20();
            *(unsigned short *)0x04000050 = 0;
            *(unsigned short *)0x04001050 = 0;
            func_02043534(0);
            func_020435F4(0);
            return 12;
        }
    }
    return 1;
}

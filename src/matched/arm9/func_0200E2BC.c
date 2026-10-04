/*
 * function: func_0200E2BC
 * address:  0x0200E2BC
 * packet:   pkt_0200E2BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734     0x02030734  arm
 *   func_020307B0     0x020307B0  arm
 *   func_02007248     0x02007248  thumb
 *   func_0200E06C     0x0200E06C  thumb
 *   memcmp            0x0203EFC8  arm
 *   sFile_020A720C    0x020A720C  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 lo  : 11;
    u32 mid : 12;
    u32 hi  : 6;
    u32 top : 3;
} Key;

extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern void  func_020307B0(void *p);
extern u32   func_02007248(void *a, u32 b, u32 c, void *d, u32 e);
extern void func_0200E06C(char *p);
extern int   memcmp(const void *a, const void *b, u32 n);
extern char  sFile_020A720C[];

u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode)
{
    u32 *buf;
    Key *key = (Key *)a1;
    u32 found = 0;
    s32 i;
    s32 j;

    buf = func_02030734((u32)heap, 0x850, 1, sFile_020A720C, 0x1ac);
    for (i = 0; i < 2; i++) {
        if (func_02007248(a0, 0x3d, i, buf, 0x850) == 1) {
            func_0200E06C((char *)buf);
            for (j = 0; j < 530; j++) {
                if (mode == 1) {
                    if (key->lo != ((Key *)buf)[j].lo) continue;
                    if (key->hi != ((Key *)buf)[j].hi) continue;
                    found = 1;
                    break;
                } else {
                    if (memcmp(&buf[j], a1, 4) != 0) continue;
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1) break;
    }
    func_020307B0(buf);
    return found;
}

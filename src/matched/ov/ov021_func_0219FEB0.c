/*
 * function: func_0219FEB0
 * address:  0x0219FEB0
 * packet:   pkt_ov021_0219FEB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_0216D678  0x0216D678  thumb  ov010
 *   func_0219FFD4  0x0219FFD4  thumb  ov021
 *   func_021A000C  0x021A000C  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 *   func_02050880  0x02050880  arm
 *   data_021D8548  0x021D8548  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { u8 b[4]; } U8x4;

extern const U8x4 data_021D8548;

extern u16 func_0216D678(void *p);
extern u32 func_0219FFD4(u32);
extern void func_0205082C(void *p, int idx, u16 h);
extern void func_0205085C(void *p, int idx, u16 v);
extern u16 func_02050880(u8 *p, int i);
extern void func_021A000C(u32, u32, u32, u32, u32);

void func_0219FEB0(u8 *s, u32 a, u32 r, u16 id)
{
    U8x4 tbl;
    u32 flag;
    u16 k;
    u32 y;
    u32 x;

    flag = 0;
    y = func_0219FFD4(a);
    x = func_0216D678((void *)a);
    k = y + x * 4;
    if (s[3] != 0 && x == s[1])
        s[3] = flag;
    if (y != s[0]) {
        flag = 1;
        s[1] = x;
        s[0] = y;
        s[2] = 0;
        func_0205082C((void *)r, id, k);
    } else if (x != s[1]) {
        flag = 1;
        if (x == 0) {
            if (s[1] == 0) {
                func_0205082C((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            } else {
                if (s[3] == 0) {
                    s[3]++;
                    flag = 0;
                    goto tail;
                }
                tbl = data_021D8548;
                s[2] = func_02050880((u8 *)r, id);
                if (s[2] >= 4)
                    s[2] = 0;
                s[2] = tbl.b[s[2]];
                func_0205082C((void *)r, id, k);
                s[1] = x;
                s[3] = 0;
            }
        } else {
            if (s[1] != 0) {
                s[2] = func_02050880((u8 *)r, id);
                s[2] = (s[2] >= 2) ? 0 : 2;
            }
            func_0205082C((void *)r, id, k);
            func_0205085C((void *)r, id, s[2]);
            s[1] = x;
            s[3] = 0;
        }
    }
tail:
    func_021A000C(a, r, id, flag, 0);
}

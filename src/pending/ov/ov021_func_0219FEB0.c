/*
 * function: func_0219FEB0
 * address:  0x0219FEB0
 * packet:   pkt_ov021_0219FEB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; blocked at MATCH only by unlabelled leaves with no witness
 * outside this range (every concrete byte agrees):
 *   func_0205082C (arm9, Ilias's):
 *     void func_0205082C(u8 *p, int i, u16 v)
 *     { u8 *e = *(u8 **)(p + 0x18) + i * 40; *(u16 *)(e + 0xe) = v; func_020500A0(e); }
 *   func_02050880 (arm9, Ilias's):
 *     u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }
 *   func_0216D678 (ov010 thumb leaf, asm ldrh r0,[r0,#0x2a]; bx lr), not filed here
 *     because arm9 leaves are also among the blockers.
 *   (arm9 leaf C as verified EXACT in the headers of src/pending/ov/ov021_func_0219F3F0.c
 *   and ov021_func_0219FC68.c.)
 * The x == 0 arms must each write out s[1] = x; s[3] = 0 (not share it after the
 * if): that is what makes the s[1] == 0 arm a bare `b` onto the other arm's call.
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

extern u32 func_0216D678(u32);
extern u32 func_0219FFD4(u32);
extern void func_0205082C(u32, u32, u32);
extern void func_0205085C(u32, u32, u32);
extern u8 func_02050880(u32, u32);
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
    x = func_0216D678(a);
    k = y + x * 4;
    if (s[3] != 0 && x == s[1])
        s[3] = flag;
    if (y != s[0]) {
        flag = 1;
        s[1] = x;
        s[0] = y;
        s[2] = 0;
        func_0205082C(r, id, k);
    } else if (x != s[1]) {
        flag = 1;
        if (x == 0) {
            if (s[1] == 0) {
                func_0205082C(r, id, k);
                s[1] = x;
                s[3] = 0;
            } else {
                if (s[3] == 0) {
                    s[3]++;
                    flag = 0;
                    goto tail;
                }
                tbl = data_021D8548;
                s[2] = func_02050880(r, id);
                if (s[2] >= 4)
                    s[2] = 0;
                s[2] = tbl.b[s[2]];
                func_0205082C(r, id, k);
                s[1] = x;
                s[3] = 0;
            }
        } else {
            if (s[1] != 0) {
                s[2] = func_02050880(r, id);
                s[2] = (s[2] >= 2) ? 0 : 2;
            }
            func_0205082C(r, id, k);
            func_0205085C(r, id, s[2]);
            s[1] = x;
            s[3] = 0;
        }
    }
tail:
    func_021A000C(a, r, id, flag, 0);
}

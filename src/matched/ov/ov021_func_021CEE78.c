/*
 * function: func_021CEE78
 * address:  0x021CEE78
 * packet:   pkt_ov021_021CEE78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: func_02008494 (arm9 unlabelled leaf, Ilias's; no witness outside
 * the range). Verified EXACT arm9 thumb leaf C for it:
 *   extern void func_02082D44(const void *a, void *b, unsigned n);  (arm)
 *   void func_02008494(void *a, void *b) { func_02082D44(a, b, 0x20); }
 *
 * symbols:
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02008494  0x02008494  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  name[0x20];
    u8  mac[6];
    u8  used;
    u8  pad;
    s16 timer;
    u8  pad2[2];
} Ent;

typedef struct {
    u32  f0;
    u32  f4;
    Ent  e[16];
    Ent *cur;
    u8   pad[5];
    u8   f2d1;
    u8   pad2[2];
    u16  f2d4;
} N;

extern int func_0203EFC8(const void *a, const void *b, u32 n);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_02008494(u32 name, void *dst);

void func_021CEE78(u8 *p, u8 *a, u32 b)
{
    N *n = (N *)(p + 0x13c);
    int i;

    for (i = 0; i < 16; i++) {
        if (n->e[i].used == 1 && func_0203EFC8(n->e[i].mac, a, 6) == 0) {
            n->e[i].timer = 150;
            return;
        }
    }
    for (i = 0; i < 16; i++) {
        if (n->e[i].used == 0) {
            func_02082D44(a, n->e[i].mac, 6);
            func_02008494(b, n->e[i].name);
            n->e[i].timer = 150;
            n->e[i].used = 1;
            n->f2d1 = 1;
            return;
        }
    }
}

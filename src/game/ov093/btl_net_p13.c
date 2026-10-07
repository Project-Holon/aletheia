/*
 * file:     btl_net_p13.c
 * unit:     yes
 * function: func_021D4D24, func_021D4D5C, func_021D4D64
 * address:  0x021D4D24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   d_021F3A98     0x021F3A98  data  ov093  a1
 *   func_020307B0 0x020307B0 arm
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 type : 8;
    u32 size : 24;
} Hdr;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082D44(const void *, void *, u32);
void *func_021D4D24(u32 a, u16 b);
void func_021D4D5C(void *p);
void func_021D4D64(u32 *p, const void *src, u32 a);
extern const char d_021F3A98[];


void *func_021D4D24(u32 a, u16 b)
{
    Hdr *h = sub_02030734(b, a + 4, 1, d_021F3A98, 0x477);

    h->size = a;
    h->type = 4;
    return h;
}

void func_021D4D5C(void *p) { func_020307B0(p); }

void func_021D4D64(u32 *p, const void *src, u32 a)
{
    *p = (*p & ~255u) | (u8)a;
    func_02082D44(src, p + 1, *p >> 8);
}

/*
 * function: func_021BE7EC
 * address: 0x021BE7EC
 * packet: pkt_ov099_021BE7EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: byte bitfield preserves the original left/right shift extraction; declaration order preserves local stack slots.
 * prototypes: C23B8 own tail forwarder void(void) preserves loaded index and live pointer return; C23C0 own void forwarder leaves R0 live for the original test; BDD48/BDD54 own u8 returns are widened to preserve original explicit result truncations.
 * symbols:
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021BDDA8 0x021BDDA8 thumb ov099
 *   func_021B9B00 0x021B9B00 thumb ov099
 *   func_02009918 0x02009918 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 low : 2; u8 flag : 2; u8 high : 4; } Flags;
extern void *func_021C23B8(int);
extern u32 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern int func_021C23C0(void *);
extern int func_021C27E0(void *);
extern void *func_021BE2A8(char *, int);
extern int func_021BDDA8(int);
extern void func_021B9B00(void *, char *, u8);
extern void func_02009918(void *, u32, u32, u32);
int func_021BE7EC(char *p)
{
    int count = 0;
    int i;
    char *s, *h;
    u8 a, b;
    int old, next;
    for (i = 0; i < 32; i++) {
        s = func_021C23B8(i);
        a = (u8)func_021BDD48(p, s);
        b = (u8)func_021BDD54(p, s);
        if (func_021C23C0((void *)i) == 0) a = 0;
        if (a != *(u8 *)(p + i + 0x50) ||
            b != *(u8 *)(p + i + 0x70) ||
            *(u8 *)(p + i + 0x90) != func_021C27E0(s)) {
            h = func_021BE2A8(p, i + 1);
            if (h != 0) {
                old = func_021BDDA8(*(u8 *)(p + i + 0x50));
                next = func_021BDDA8(a);
                if (old == 1 && next == 0) func_021B9B00(p + 0x274, h, 0);
                else if (old == 0 && next == 1) func_021B9B00(p + 0x274, h, 1);
                func_02009918(*(void **)(p + 4), i, 8, *(u8 *)(s + 0x14));
                func_02009918(*(void **)(p + 4), i, 9, ((Flags *)(s + 0x1b))->flag);
                func_02009918(*(void **)(p + 4), i, 1, *(u32 *)s);
                func_02009918(*(void **)(p + 4), i, 0, *(u32 *)(s + 4));
            }
            *(u8 *)(p + i + 0x50) = a;
            *(u8 *)(p + i + 0x70) = b;
            *(u8 *)(p + i + 0x90) = func_021C27E0(s);
            count++;
        }
    }
    return count;
}

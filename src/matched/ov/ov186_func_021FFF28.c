/*
 * packet: pkt_ov186_021FFF28
 * function: func_021FFF28
 * address: 0x021FFF28
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 */
extern void func_021FB964(int, int, unsigned short);
extern int func_021FC20C(char *);
extern int func_021FC214(char *);
extern void *func_021FC6A4(unsigned short, unsigned char, unsigned char, unsigned, unsigned char, unsigned char, void *, unsigned short);
extern void func_021FC868(void *, int, int, int);
extern void func_021FC754(char *, void *, void *, void *, unsigned short);
typedef struct Work { char pad0[0x14]; unsigned char flags[9]; char pad1[7]; unsigned short heap; unsigned short pad2; char *owner; char pad3[0x10]; void *resource; char *slots[9]; char pad4[0xc]; int state; } Work;
void func_021FFF28(Work *p)
{
    int a, b, i;
    unsigned color;
    unsigned char x, y;
    p->state = 0;
    func_021FB964((int)p->owner, 20, p->heap);
    a = func_021FC20C(p->owner);
    b = func_021FC214(p->owner);
    for (i = 0; i < 9; i++) {
        x = (i % 5) * 6 + 2;
        y = 6;
        if (i < 5) y = 0;
        p->slots[i] = func_021FC6A4(4, x, y + 4, 4, 2, 14, p->resource, p->heap);
        color = 0x3da0;
        if (!p->flags[i]) color = 0x2da0;
        func_021FC868(p->slots[i], 0, 0, 1);
        func_021FC754(p->slots[i], (void *)b, (void *)(i + 0x3a), (void *)a, color);
    }
}

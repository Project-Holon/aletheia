/*
 * function: func_021B6A3C
 * address: 0x021B6A3C
 * packet: pkt_ov098_021B6A3C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: lead ends 021B6B5A, alignment 2 B; existing B5C/B68 unit through 6B74; unlabelled 24 B flag leaf at 6B74.
 * prototype: 021B6CDC unused a1/a2 omitted, full body overwrites all outgoing arguments; 02035C60 return is observed live at 021B6AE4 despite owner void prototype.
 * symbols:
 *   func_021B6C90 0x021B6C90 thumb ov098
 *   func_021B6CDC 0x021B6CDC thumb ov098
 *   func_0201CE20 0x0201CE20 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec3;
extern void func_021B6C90(char *, int);
extern int func_021B6CDC(u8 *);
extern void func_0201CE20(void *);
extern u32 func_0201CE30(void *);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *);
extern void func_0201DD68(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
int func_021B6A3C(u8 *p)
{
    switch (p[0x39]) {
    case 0:
        func_021B6C90((char *)p + 4, p[0x38]);
        p[0x39]++;
    case 1:
        if (!func_021B6CDC(p + 4)) break;
        if (p[0x38]) {
            p[0x39] = 6;
            break;
        }
        if (*(void **)p) func_0201CE20(*(void **)p);
        p[0x39]++;
    case 2:
        if (*(void **)p) {
            *(u32 *)(p + 0x3c) = func_0201CE30(*(void **)p);
            if (*(u32 *)(p + 0x3c)) {
                p[0x39] = 3;
                if (*(u32 *)(p + 0x3c) == 2) p[0x3a] = 1;
            }
        } else return 1;
        break;
    case 3:
        if ((func_020362DC() & 3) || func_02035C60()) *(u16 *)(p + 0x40) = 0;
        if (*(u16 *)(p + 0x40)) (*(u16 *)(p + 0x40))--;
        else p[0x39] = 5;
        break;
    case 4:
        if (*(u16 *)(p + 0x40)) (*(u16 *)(p + 0x40))--;
        else p[0x39] = 5;
        break;
    case 5:
        if (*(u32 *)(p + 0x3c) == 2) {
            func_0201DD68();
            func_0201CE48(*(struct Rec3 **)p);
            *(void **)p = 0;
            p[0x39] = 6;
            return 1;
        } else {
            func_0201CE38(*(void **)p);
            p[0x39] = 2;
            *(u16 *)(p + 0x40) = *(u16 *)(p + 0x42);
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}

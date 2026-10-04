/*
 * function: func_021CE7D4
 * address: 0x021CE7D4
 * packet: pkt_ov093_021CE7D4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021BA004 0x021BA004 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021EA6B0 0x021EA6B0 thumb ov093
 *   func_021D7F38 0x021D7F38 thumb ov093
 *   func_021F87EC 0x021F87EC thumb ov094
 *   func_021F8774 0x021F8774 thumb ov094
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 flag : 1; u8 rest : 7; } Flags;
extern u8 func_021B904C(u8 *p, int k);
extern u16 func_021BA004(char *p, int i);
extern unsigned short func_021BA020(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern int func_021EA6B0(char *, u16, u16);
extern int func_021D7F38(u32 n);
extern void func_021F87EC(u32);
extern int func_021F8774(void);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D90(u16, u16);
extern int func_021F7EB4(void);
extern int func_021EA710(u32 *p);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CE4D0(u8 *);

u32 func_021CE7D4(u8 *p, int *st)
{
    u32 i;
    u16 k;
    u32 z;
    switch (*st) {
    case 0:
        z = 0;
        i = func_021B904C(*(void **)p, 0);
        k = func_021BA004(*(void **)p, i);
        func_021F7F58(func_021BA020(*(void **)p, i), 9, 0, 0, z);
        func_021F7998(0x270);
        func_021EA6B0(*(char **)(p + 0x54), k, *(u16 *)(p + 0x19e));
        if ((u16)(*(u16 *)(p + 0x19e) + 0xffed) <= 1 &&
            func_021D7F38(func_021BA020(*(void **)p, i)) && !((Flags *)(p + 0x1b2))->flag) {
            func_021F87EC(0x47b);
            if (!func_021F8774()) {
                func_02005E30(8);
                *st = 1;
                break;
            }
        }
        *st = 2;
        break;
    case 1:
        if (!func_02005E50()) {
            func_02005D90(0x47b, 0xffff);
            p[0x1b2] = (p[0x1b2] & ~1) | 1;
            ++*st;
        }
        break;
    case 2:
        if (!func_021F7EB4() && func_021EA710(*(void **)(p + 0x54))) {
            func_021F7998(0x271);
            ++*st;
        }
        break;
    case 3:
        if (!func_021F7EB4()) func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    }
    return 0;
}

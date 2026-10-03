/*
 * function: func_021B7758
 * address: 0x021B7758
 * packet: pkt_ov093_021B7758
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: k starts at 1 and is conditionally assigned 3; ternary reverses the short branch.
 * symbols:
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D4438 0x021D4438 thumb ov093
 *   func_021D44CC 0x021D44CC thumb ov093
 *   func_021D4D24 0x021D4D24 thumb ov093
 *   func_021D4D64 0x021D4D64 thumb ov093
 *   func_021D4680 0x021D4680 thumb ov093
 *   func_021D4784 0x021D4784 thumb ov093
 *   func_021D4D5C 0x021D4D5C thumb ov093
 *   func_021D47A4 0x021D47A4 thumb ov093
 *   func_021D4800 0x021D4800 thumb ov093
 *   func_021B93E0 0x021B93E0 thumb ov093
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021BA128 0x021BA128 thumb ov093
 *   func_021BA648 0x021BA648 thumb ov093
 *   func_021B9460 0x021B9460 thumb ov093
 *   func_0201A918 0x0201A918 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 a:1; u8 b:1; } B;
extern int func_021D4270(void);
extern void func_021D4AF4(u8);
extern int func_021D4B18(u8);
extern int func_021D4438(void *);
extern int func_021D44CC(void);
extern void *func_021D4D24(u32,u16);
extern void func_021D4D64(u32 *p, const void *src, u32 a);
extern u32 func_021D4680(u32 *a);
extern int func_021D4784(u32 a);
extern void func_021D4D5C(void *);
extern void *func_021D47A4(u8);
extern void func_021D4800(void);
extern void func_021B93E0(void *,void *,int);
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern void func_021BA128(void *,u8,void *);
extern void func_021BA648(void *,u8,void *);
extern void func_021B9460(void *,void *,u8);
extern int func_0201A918(void);
int func_021B7758(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    u8 *desc;
    int k;
    q = *(u8 **)p;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4AF4(2);
        ++*state;
        break;
    case 1:
        if (func_021D4B18(2)) ++*state;
        break;
    case 2:
        if (func_021D4438(*(void **)(q + 0x24))) ++*state;
        break;
    case 3:
        if (func_021D44CC()) {
            if (!p[0x471]) *state = 10;
            else {
                if (p[0x46e]) {
                    *(void **)(p + 0x2c4) = func_021D4D24(func_0201A918(), (*(u16 *)(p + 0x468) & 0x7fff) | 0x8000);
                }
                p[0x470] = 0;
                ++*state;
            }
        }
        break;
    case 4:
        k = 1;
        if (p[0x470]) k = 3;
        p[0x472] = k;
        if (p[0x46e]) func_021D4D64(*(void **)(p + 0x2c4), *(void **)(q + p[0x472] * 4 + 0x24),p[0x472]);
        func_021D4AF4(p[0x470] + 6);
        ++*state;
        break;
    case 5:
        if (func_021D4B18(p[0x470] + 6)) ++*state;
        break;
    case 6:
        if (!p[0x46e] || func_021D4680(*(void **)(p + 0x2c4))) ++*state;
        break;
    case 7:
        if (func_021D4784(p[0x472])) {
            ++p[0x470];
            if (p[0x470] >= p[0x471]) {
                if (p[0x46e]) {
                    func_021D4D5C(*(void **)(p + 0x2c4));
                    *(void **)(p + 0x2c4) = 0;
                }
                *state = 10;
            } else *state = 4;
        }
        break;
    case 10:
        func_021B93E0(p + 0xc8,p,0);
        desc = p + 0xc8;
        for (i = 0; i < 4; ++i) {
            if (func_021B8B9C(p,i)) {
                func_021BA128(p,i,func_021D47A4(i));
                func_021BA648(p,i,func_021D47A4(i));
                func_021B9460(desc,p,i);
            }
        }
        ++*state;
        break;
    case 11:
        func_021B93E0(p + 0x1b0,p,1);
        for (i = 0; i < 4; ++i) {
            if (func_021B8B9C(p,i)) func_021B9460(p + 0x1b0,p,i);
        }
        ++*state;
        break;
    case 12:
        func_021D4800();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}

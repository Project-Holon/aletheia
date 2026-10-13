/*
 * function: func_021B7968
 * address: 0x021B7968
 * packet: pkt_ov093_021B7968
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the bank string object is its own inner-block local declared
 *   before the copy index (void *str; int j;); reusing the outer s or
 *   declaring str after j swapped r4/r5 (17 bytes).
 * leaves: ov093 021D49B0 (+0x1E4) and 021D49CC (+0x1EC) resolve through
 *   their own shards pkt_ov093_021D49B0/pkt_ov093_021D49CC (W82 R11).
 * symbols:
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4AF4 0x021D4AF4 thumb ov093
 *   func_021D4B18 0x021D4B18 thumb ov093
 *   func_021D4808 0x021D4808 thumb ov093
 *   func_021D4898 0x021D4898 thumb ov093
 *   func_021D48CC 0x021D48CC thumb ov093
 *   func_021D4908 0x021D4908 thumb ov093
 *   func_021D49B0 0x021D49B0 thumb ov093
 *   func_021D49CC 0x021D49CC thumb ov093
 *   func_021D49E0 0x021D49E0 thumb ov093
 *   func_021D4A04 0x021D4A04 thumb ov093
 *   func_021B9E38 0x021B9E38 thumb ov093
 *   func_021B9EF0 0x021B9EF0 thumb ov093
 *   func_021BA670 0x021BA670 thumb ov093
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045808 0x02045808 arm
 *   func_020084D4 0x020084D4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { START, END = 15 } Index;
typedef struct { u8 a:1; u8 b:1; u8 c:1; } Bits;
extern int func_021D4270(void);
struct A;
struct B;
extern void func_021D4AF4(int a);
extern int func_021D4B18(int a);
extern int func_021D4808(u32 a);
extern int func_021D4898(void);
extern void *func_021D48CC(u8);
extern u32 func_021D4908(void *);
extern int func_021D49B0(void);
extern void *func_021D49CC(void);
extern void func_021D49E0(void);
extern void func_021D4A04(void);
extern void func_021B9E38(char *p, int a, int b);
extern void func_021B9EF0(struct A *p, const struct B *src);
extern void func_021BA670(char *p, u8 k, void *dst);
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
int func_021B7968(u8 *p,u32 *state)
{
    u8 *q;
    u32 i;
    u32 offset;
    void *bank;
    void *s;
    void *s2;
    u16 *src;
    u16 *dst;
    u16 buf[16];
    int k;
    q = *(u8 **)p;
    if (func_021D4270()) {
        ((Bits *)(p + 0x473))->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        func_021D4AF4((u8)4);
        ++*state;
        break;
    case 1:
        if (func_021D4B18((u8)4)) ++*state;
        break;
    case 2:
        if (func_021D4808((u32)(*(void **)(p + 0xc0)))) ++*state;
        break;
    case 3:
        if (func_021D4898()) {
            for (i = 0; i < p[0x46b]; ++i) {
                s = func_021D48CC(i);
                if (s) {
                    offset = i * 0x28;
                    func_021B9E38((char *)(p + 0x20 + offset),*(u16 *)(p + 0x468),(int)s);
                    if (i != p[0x46c] && ((Bits *)(q + 0xc1))->c) {
                        void *str;
                        int j;
                        bank = func_02045B38(0,2,0x51,*(u16 *)(p + 0x468));
                        str = func_02045EC0(bank,15);
                        func_02045C04(bank);
                        src = STRBUF_GetChars(str);
                        for (j = START; j < END && (u32)j < func_020458F8(str); ++j) buf[j] = src[j];
                        dst = buf;
                        dst[j] = func_02045A98();
                        func_02045808(str);
                        func_020084D4((u32)(*(void **)(p + offset + 0x20)),dst);
                        func_02045808(*(void **)(p + offset + 0x24));
                        bank = func_02045B38(0,2,0x51,*(u16 *)(p + 0x468));
                        s2 = func_02045EC0(bank,15);
                        func_02045C04(bank);
                        *(void **)(p + offset + 0x24) = s2;
                    }
                    func_021BA670((char *)p,i,*(void **)(p + offset + 0x20));
                }
            }
            ++*state;
        }
        break;
    case 4:
        if (!p[0x471]) *state = 10;
        else { p[0x470] = 0; ++*state; }
        break;
    case 5:
        func_021D4AF4((u8)(p[0x470] + 8));
        ++*state;
        break;
    case 6:
        if (func_021D4B18((u8)(p[0x470] + 8))) ++*state;
        break;
    case 7:
        k = 1;
        if (p[0x470]) k = 3;
        p[0x472] = k;
        if (p[0x46e] && !func_021D4908(*(void **)(q + p[0x472] * 4 + 0x48))) break;
        ++*state;
    case 8:
        if (func_021D49B0()) {
            func_021B9EF0((struct A *)(p + 0x20 + p[0x472] * 0x28),func_021D49CC());
            func_021D49E0();
            ++p[0x470];
            if (p[0x470] >= p[0x471]) *state = 10;
            else *state = 5;
        }
        break;
    case 10:
        func_021D4A04();
        ++*state;
        break;
    default:
        return 1;
    }
    return 0;
}

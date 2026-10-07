/*
 * file:     monolith_tool_p02.c
 * unit:     yes
 * function: func_021B6524, func_021B652C, func_021B6538, func_021B6540, func_021B6588, func_021B65B4
 * address:  0x021B6524
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02045088  0x02045088  arm
 *   func_020450C8  0x020450C8  arm
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_02021EE4  0x02021EE4  thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA794     0x021BA794  data  a4
 *   d_021BA7B4     0x021BA7B4  data  a4
 */
struct Obj02021EE4;
struct PalAnmSlot;
struct BgTemplate;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void func_020215A0(struct PalAnmSlot *, u32);
extern u32 func_02021540(void *a0);
void func_021B6524(void);
void func_021B652C(void);
void func_021B6538(void);
void func_021B6540(int *p);
void func_021B6588(struct PalAnmSlot **p);
void func_021B65B4(void);
extern char d_021BA794;
extern char d_021BA7B4;

/*
 * Three ARM9 thunks that share a literal-pool tail-call shape.
 */
void func_021B6524(void)
{
    void func_0203F9B4(void);
    func_0203F9B4();
}

void func_021B652C(void)
{
    void func_02045088(u16 heapId);
    func_02045088(0x61);
}


void func_021B6538(void)
{
    void func_020450C8(void);
    func_020450C8();
}

void func_021B6540(int *p)
{
    void *func_02021518(u32 heap);
    void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
    void func_02021EE4(struct Obj02021EE4 *o, int v);

    *p = (int)func_02021518(0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 2, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 3, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 0, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 1, 0x1c0, 0x61);
    func_02021EE4((struct Obj02021EE4 *)(*p), 1);
}

void func_021B6588(struct PalAnmSlot **p)
{
    func_020215A0(*p, 2);
    func_020215A0(*p, 3);
    func_020215A0(*p, 0);
    func_020215A0(*p, 1);
    func_02021540(*p);
}

void func_021B65B4(void)
{
    void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
    void func_02041300(int, int, int, int, int, int, int);
    void func_02040588(unsigned char which, unsigned char enable);
    int i;

    func_0203FCA0((int)3, (const struct BgTemplate *)(&d_021BA794), (int)0);
    func_0203FCA0((int)7, (const struct BgTemplate *)(&d_021BA7B4), (int)0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    for (i = 0; i <= 7; i++) {
        func_02040588((u8)i, (int)0);
    }
    func_02040588((u8)3, (int)1);
    func_02040588((u8)7, (int)1);
}

/*
 * file:     event_poke_status_p11.c
 * unit:     yes
 * function: func_02159F28, func_02159F54, func_02159F80
 * address:  0x02159F28
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159F04 0x02159F04 thumb ov010
 */
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ent { u8 f00; u8 f01; u16 f02; u16 f04; } Ent;

typedef signed short   s16;

extern Ent *func_02159F04(int, int);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32, u32);
void func_02159F28(int a, int b, int flag);
int func_02159F54(int a, int b);
int func_02159F80(void);

/*
 * extent: two bytes of zero alignment padding at 0x02159F52.
 */
void func_02159F28(int a, int b, int flag)
{
    Ent *p = func_02159F04(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(func_0201296C((const struct BigObj *)a), p->f02);
        if (flag)
            *q = p->f04;
        else
            *q = 0;
    }
}

int func_02159F54(int a, int b)
{
    Ent *p = func_02159F04(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(func_0201296C((const struct BigObj *)a), p->f02);
        if (p->f04 == *q)
            return 1;
        else
            return 0;
    }
    return 0;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Constant leaf: `movs r0, #N; bx lr`.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159F80.c \
 *       --func func_02159F80 --addr 0x02159F80 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_02159F80(void) { return 1; }

/*
 * file:     unit_021DDB38_p01.c
 * unit:     yes
 * function: func_021DDF74, func_021DDFBC, func_021DDFF8
 * address:  0x021DDF74
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DDB38  0x021DDB38  arm
 *   func_02182AC0   0x02182AC0  arm  ov009
 *   func_021DDBE4   0x021DDBE4  arm  ov175
 *   g_021E3A8C      0x021E3A8C  data
 *   g_021E3B4C      0x021E3B4C  data
 *   func_02183A24  0x02183A24  arm
 *   g_021E3B54     0x021E3B54  data
 */
struct SAKEField;
struct SAKERequestInternal;
typedef int s32;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
} Blk;

extern s32 func_021DDB38(s32, s32);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_021DDBE4(struct SAKERequestInternal *request, struct SAKEField *fields, int numFields);
extern int func_02183A24(u32, u32 *, u32);
s32 func_021DDF74(char *p);
u32 func_021DDFBC(char *obj);
int func_021DDFF8(char *p);
extern u32 g_021E3A8C[];
extern u32 g_021E3B4C[];
extern u32 g_021E3B54[];


s32 func_021DDF74(char *p)
{
    s32 *q = *(s32 **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[2] < 0)
        return 6;
    if (q[1] == 0) {
        if (q[2] > 0)
            return 5;
    }
    return func_021DDB38(q[1], q[2]);
}


u32 func_021DDFBC(char *obj)
{
    Blk *b = *(Blk **)(obj + 8);

    func_02182AC0((void *)(*(u32 *)(obj + 0x18)), (char *)((u32)g_021E3A8C), (char *)((u32)g_021E3B4C), (char *)b->f0);
    func_021DDBE4((struct SAKERequestInternal *)((u32)obj), (struct SAKEField *)b->f4, b->f8);
    return 0;
}


/*
 * Hand the +0x1c handle, the shared 0x021E3B54 descriptor and the +0x0c value
 * to func_02183A24; a refusal (0) is reported as 5.
 */
int func_021DDFF8(char *p)
{
    return func_02183A24(*(u32 *)(p + 0x1c), g_021E3B54, *(u32 *)(p + 0xc)) == 0 ? 5 : 0;
}

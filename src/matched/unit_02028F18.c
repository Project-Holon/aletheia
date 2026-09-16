/*
 * unit:     yes
 * function: func_02028F18
 * address:  0x02028F18
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02028FD0  0x02028FD0  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct SoundParam2 {
    unsigned char pad00[4];
    u32 group;    /* +0x04 */
    unsigned char pad08[4];
    u32 valC;     /* +0x0c */
    unsigned char pad10[8];
    u16 val18;    /* +0x18 */
    u16 val1a;    /* +0x1a */
    u32 kind;     /* +0x1c */
};

extern u32 func_02028FD0(struct SoundParam2 *obj, u32 kind);

void func_02028F18(struct SoundParam2 *obj, u16 a1)
{
    if (func_02028FD0(obj, 1)) {
        obj->kind = 1;
        obj->val18 = a1;
    }
}

void func_02028F30(struct SoundParam2 *obj, u16 a1)
{
    if (func_02028FD0(obj, 2)) {
        obj->kind = 2;
        obj->val1a = a1;
    }
}

void func_02028F48(struct SoundParam2 *obj, u16 a1)
{
    if (func_02028FD0(obj, 3)) {
        obj->kind = 3;
        obj->val1a = a1;
    }
}

void func_02028F60(struct SoundParam2 *obj, u16 a1, u16 a2)
{
    if (func_02028FD0(obj, 4)) {
        obj->kind = 4;
        obj->val18 = a2;
        obj->val1a = a1;
    }
}

void func_02028F7C(struct SoundParam2 *obj, u32 a1, u16 a2, u16 a3)
{
    if (func_02028FD0(obj, 5)) {
        obj->kind = 5;
        obj->valC = a1;
        obj->val18 = a3;
        obj->val1a = a2;
    }
}

void func_02028F9C(struct SoundParam2 *obj, u32 a1, u16 a2)
{
    if (func_02028FD0(obj, 6)) {
        obj->kind = 6;
        obj->valC = a1;
        obj->val1a = a2;
    }
}

void func_02028FB8(struct SoundParam2 *obj, u32 a1)
{
    if (func_02028FD0(obj, 7)) {
        obj->kind = 7;
        obj->valC = a1;
    }
}

/*
 * file:     zukan_detail_form_p05.c
 * unit:     yes
 * function: func_021C4AC4, func_021C4AF4, func_021C4B2C
 * address:  0x021C4AC4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   ov208_func_021C4B60  0x021C4B60  thumb
 */
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Ov208Menu_021C4AC4 {
    u8  pad0[0x568];
    u32 slot[5];
    u32 print[5];
};

struct Ov208Menu_021C4AF4 {
    u8  pad0[0x568];
    u32 slot[5];
    u32 print[5];
};

struct Ov208Menu_021C4B2C {
    u8  pad0[0x57c];
    u32 print[5];
};

extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void ov208_func_021C4B60(void *a0, struct Ov208Menu_021C4B2C *p, int key, int i);
void func_021C4AC4(u16 *heap, struct Ov208Menu_021C4AC4 *p);
void func_021C4AF4(u16 *heap, struct Ov208Menu_021C4AF4 *p);
void ov208_func_021C4B2C(void *a0, struct Ov208Menu_021C4B2C *p, int key);

void func_021C4AC4(u16 *heap, struct Ov208Menu_021C4AC4 *p)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->print[i] = func_0201C440((void *)(*heap));
        p->slot[i] = 0;
    }
}

void func_021C4AF4(u16 *heap, struct Ov208Menu_021C4AF4 *p)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->slot[i] = 0;
        func_0201C6EC((struct PrintSys *)p->print[i]);
        func_0201C4C0((struct PrintSys *)p->print[i]);
    }
}


void ov208_func_021C4B2C(void *a0, struct Ov208Menu_021C4B2C *p, int key)
{
    u8 i;

    for (i = 0; i < 5; i++) {
        func_0201C4E4((struct PrintSys *)p->print[i]);
        ov208_func_021C4B60(a0, p, key, i);
    }
}

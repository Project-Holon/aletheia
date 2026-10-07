/*
 * file:     unit_021C4CB4_p04.c
 * unit:     yes
 * function: func_021C5238, func_021C5278, func_021C52CC
 * address:  0x021C5238
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5300 0x021C5300 thumb ov127
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4B90 0x021C4B90 thumb ov127
 *   func_021C4A54 0x021C4A54 thumb ov127
 */
typedef unsigned short u16;

typedef struct { u16 x, y; } Pos;

typedef unsigned char  u8;

struct pair { u16 a,b; };

extern int func_021C5300(u8 *p);
extern Pos func_021C4AC4(void *);
extern void func_021C4B90(void *, Pos);
extern struct pair func_021C4A54(struct pair,int);
int func_021C5238(void *p);
int func_021C5278(void *p);
int func_021C52B8(void);
int func_021C52BC(void *p);
int func_021C52C4(void *p);
struct pair func_021C52CC(struct pair p,int i);

int func_021C5238(void *p)
{
    int r = func_021C5300(p);
    if (r == 1) {
        Pos v = func_021C4AC4(p);
        func_021C4B90(p, v);
    }
    return r;
}

int func_021C5278(void *p)
{
    int r = func_021C5300(p);
    if (r == 1) {
        Pos v = func_021C4AC4(p);
        func_021C4B90(p, v);
    }
    return r;
}

int func_021C52B8(void) { return 0; }

int func_021C52BC(void *p) { return func_021C5300(p); }

int func_021C52C4(void *p) { return func_021C5300(p); }

struct pair func_021C52CC(struct pair p,int i)
{
 return func_021C4A54(p,i);
}

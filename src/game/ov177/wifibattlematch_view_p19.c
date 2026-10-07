/*
 * file:     wifibattlematch_view_p19.c
 * unit:     yes
 * function: func_021E7CD0, func_021E7CF0, func_021E7D20
 * address:  0x021E7CD0
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021E5978 0x021E5978 thumb ov177
 *   d_021E8DBC 0x021E8DBC data a1
 */
struct Obj;
typedef struct { char pad[0x68]; void *obj[5]; } Work;

typedef struct { short x, y; unsigned short id; unsigned char a, flag; } Request;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_0204B3B4(struct Obj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern int func_021E5978(int *p, int i);
extern void *func_0204B294(void *, unsigned, unsigned, unsigned, const Request *, unsigned short, unsigned);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021E7CD0(Work *p);
unsigned func_021E7CF0(void *p, unsigned short v, unsigned short w);
void **func_021E7D20(void *owner, void *src, unsigned heap);
extern const char d_021E8DBC[];

void func_021E7CD0(Work *p)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (p->obj[i] != 0) {
            func_0204B3B4(p->obj[i]);
            p->obj[i] = 0;
        }
    }
}

unsigned func_021E7CF0(void *p, unsigned short v, unsigned short w)
{
    if (v >= 1000) {
        return 5;
    }
    if (v >= 500) {
        return 4;
    }
    if (v >= 200) {
        return 3;
    }
    if (v >= 100) {
        return 2;
    }
    if (v >= 50) {
        return 1;
    }
    return 0;
}

void **func_021E7D20(void *owner, void *src, unsigned heap)
{
    void **objs;
    Request req;
    objs = func_02030734(heap, 8, 0, d_021E8DBC, 0xBEF);
    func_02082BCC(objs, 0, 8);
    func_02082BCC(&req, 0, 8);
    req.x = 0x80;
    req.y = 0x60;
    req.id = 1;
    req.a = 1;
    req.flag = 1;
    objs[0] = func_0204B294(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), &req, 0, heap);
    func_0204B92C(objs[0], 1);
    req.id = 0;
    req.a = 0;
    req.flag = 1;
    objs[1] = func_0204B294(owner, func_021E5978(src, 2), func_021E5978(src, 0), func_021E5978(src, 4), &req, 0, heap);
    func_0204B92C(objs[1], 1);
    return objs;
}

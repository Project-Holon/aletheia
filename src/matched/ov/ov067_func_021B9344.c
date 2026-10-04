/*
 * function: func_021B9344
 * address:  0x021B9344
 * packet:   pkt_021B9344
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Elem {
    void *p;
    u8 flag;
    u8 pad[3];
};

struct S {
    u8 _0[0x34];
    int f34;
    struct Elem *arr;
    u8 _3c[0x44 - 0x3c];
    u8 count;
};

extern int func_0201C4E4(int a);
extern int func_0201C6C4(int a, int b);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);

void func_021B9344(struct S *s)
{
    u32 i;

    func_0201C4E4(s->f34);
    for (i = 0; i < s->count; i++) {
        struct Elem *e = &s->arr[i];
        int a = s->f34;

        if (e->flag != 0) {
            if (func_0201C6C4(a, (int)func_02045770((struct Descriptor *)e->p)) == 0) {
                func_02045334((struct Descriptor *)e->p);
                e->flag = 0;
            }
        }
    }
}

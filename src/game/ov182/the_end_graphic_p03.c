/*
 * file:     the_end_graphic_p03.c
 * unit:     yes
 * function: func_021B99E8, func_021B99FC, func_021B9A10, func_021B9A70, func_021B9AA8
 * address:  0x021B99E8
 * region:   ov182
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9B10  0x021B9B10  thumb  ov182
 *   func_021B9AAC  0x021B9AAC  thumb  ov182
 *   func_021B9B18  0x021B9B18  thumb  ov182
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021B9BFC 0x021B9BFC data a4
 *   d_021B9C78 0x021B9C78 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 */
struct BgTemplate;
struct DispConfig;
typedef unsigned int   u32;

typedef struct { unsigned id; unsigned v[8]; unsigned a, b; } Record_021B9A10;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {u32 id;u32 v[8];u32 a,b;} Record_021B9A70;

extern void func_021B9B10(void *);
extern void func_021B9AAC(void *);
extern void func_021B9B18(void *);
extern void func_02082BCC(void *, int, int);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u32 i);
void func_021B99E8(char *p);
void func_021B99FC(int a0, char *p);
void func_021B9A10(void *p, int heap);
void func_021B9A70(void *p);
void func_021B9AA8(void *p);
extern const unsigned d_021B9BFC[];
extern const Record_021B9A10 d_021B9C78[];


void func_021B99E8(char *p)
{
    func_021B9B10(p + 4);
    func_021B9AA8(p);
}


void func_021B99FC(int a0, char *p)
{
    func_021B9AAC(p);
    func_021B9B18(p + 4);
}

void func_021B9A10(void *p, int heap)
{
    unsigned i = 0;
    const Record_021B9A10 *r;
    unsigned id;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021B9BFC);
    for (; i < 2; i++) {
        r = &d_021B9C78[i];
        id = r->id;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)r->v, (unsigned char)r->a);
        func_020414AC(id);
        func_02040588(id, r->b);
    }
}

void func_021B9A70(void *p){u32 i;for(i=0;i<2;i++)func_020403F4((u8)d_021B9C78[i].id);func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

void func_021B9AA8(void *p){}

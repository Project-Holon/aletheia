/*
 * file:     townmap_p03.c
 * unit:     yes
 * function: func_021B9958, func_021B995C, func_021B9964, func_021B996C, func_021B99AC, func_021B99E8, func_021B9E38
 * address:  0x021B9958
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021BA040 0x021BA040 thumb ov072
 *   func_021BB0E0 0x021BB0E0 thumb ov072
 *   func_021BA3BC 0x021BA3BC thumb ov072
 *   func_021BA3EC 0x021BA3EC thumb ov072
 *   func_021BB6AC 0x021BB6AC thumb ov072
 *   func_021BB6DC 0x021BB6DC thumb ov072
 *   func_021BA69C 0x021BA69C thumb ov072
 *   func_021BB19C 0x021BB19C thumb ov072
 *   func_021BA6A8 0x021BA6A8 thumb ov072
 *   func_021BA450 0x021BA450 thumb ov072
 *   func_021BA488 0x021BA488 thumb ov072
 *   func_021BA6C8 0x021BA6C8 thumb ov072
 *   func_021BA3E8 0x021BA3E8 thumb ov072
 *   func_021BA774 0x021BA774 thumb ov072
 *   func_021BB220 0x021BB220 thumb ov072
 *   func_021BA7A4 0x021BA7A4 thumb ov072
 *   func_021BA3F4 0x021BA3F4 thumb ov072
 *   func_021BB5AC 0x021BB5AC thumb ov072
 *   func_021BB3D0 0x021BB3D0 thumb ov072
 *   func_021BB5B4 0x021BB5B4 thumb ov072
 *   func_021BA7D4 0x021BA7D4 thumb ov072
 *   func_021BA48C 0x021BA48C thumb ov072
 *   func_021B9F50 0x021B9F50 thumb ov072
 *   func_021BA0E4 0x021BA0E4 thumb ov072
 *   func_021BA5AC 0x021BA5AC thumb ov072
 *   func_021BAFA8 0x021BAFA8 thumb ov072
 *   func_021BB548 0x021BB548 thumb ov072
 *   func_021BB5EC 0x021BB5EC thumb ov072
 *   func_021BA028 0x021BA028 thumb ov072
 *   func_021BB0B4 0x021BB0B4 thumb ov072
 *   func_021BB190 0x021BB190 thumb ov072
 *   func_021BB0DC 0x021BB0DC thumb ov072
 *   func_020355C4 0x020355C4 arm
 *   d_021BBB78 0x021BBB78 data ov072 a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B974  0x0204B974  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6520  0x021B6520  thumb  ov067
 *   d_021BBB8C     0x021BBB8C  data  a4
 */
#define W(k) (*(int *)(p+(k)))
#define R(k) ((void *)(p+(k)))
struct Obj;
struct Actor;
typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef long long s64;

typedef struct { int x,y; } Pos;

typedef struct { int x,y,z; } Vec;

typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Rect;

typedef struct { u32 w[16]; } Tbl;

typedef struct {
    u8 *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} Req;

void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
extern int func_021BA040(int *);
extern int func_021BB0E0(void *);
extern void func_021BA3BC(char *,int *);
extern int func_021BA3EC(char *);
extern int func_021BB6AC(u32 *,Vec *,u32 *);
extern void func_021BB6DC(int *);
extern void func_021BA69C(char *,int *);
extern void func_021BB19C(u32 *,const u32 *);
extern void func_021BA6A8(char *,const int *);
extern void func_021BA450(int *,int *);
extern int func_021BA488(int *);
extern int func_021BA6C8(void *,void *);
extern int func_021BA3E8(int *);
extern int func_021BA774(char *p, int i);
extern void func_020061E4(u32);
extern u8 func_020355C4(void);
extern void func_021BB220(u32 *,void *);
extern void func_021BA7A4(char *,void *);
extern void func_021BA3F4(int *p, int a, int *b);
extern void func_021BB5AC(int *p, int x);
extern void func_021BB3D0(void **);
extern void func_021BB5B4(u32 *,u32);
extern void func_021BA7D4(char *);
extern void func_021BA48C(int *,int);
extern void func_021B9F50(u32 *p, void *q);
extern void func_021BA0E4(void *,void *);
extern void func_021BA5AC(void *);
extern void func_021BAFA8(void *,void *);
extern void func_021BB548(u32 *);
extern void func_021BB5EC(struct Obj *p);
extern int func_021BA028(char *);
extern void func_021BB0B4(void *,int,const Pos *,const Pos *);
extern void func_021BB190(char *,int *);
extern int func_021BB0DC(void *);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B974(struct Actor *a);
extern u32 func_021B62E0(Req *r, int heap);
extern void func_021B6520(u8 *p, u32 v);
int func_021B9958(int *p);
void func_021B995C(int *p, int x);
void func_021B9964(int *p);
void func_021B996C(int a, int *b);
void func_021B99AC(int *p, int *state);
int func_021B99E8(int *a,int unused,char *p);
void func_021B9E38(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap);
extern const Pos d_021BBB78;
extern Tbl d_021BBB8C;

int func_021B9958(int *p)
{
    return p[1];
}

void func_021B995C(int *p, int x)
{
    p[0] = x;
    p[2] = 0;
}

void func_021B9964(int *p)
{
    p[1] = 1;
}


void func_021B996C(int a, int *b)
{
    switch (b[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        b[0] = 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            b[0] = 2;
        }
        break;
    case 2:
        func_021B995C((int *)a, (int)func_021B99E8);
        break;
    }
}

/*
 * note: trailing two-byte alignment padding.
 */
void func_021B99AC(int *p, int *state) {
    switch (*state) {
    case 0: func_0204E720(3,0,16,0); *state = 1; break;
    case 1: if (func_0204E804() == 0) *state = 2; break;
    case 2: func_021B9964(p); break;
    }
}

int func_021B99E8(int *a,int unused,char *p)
{
    u8 moved;
    int w,mask,t;
    moved=0;
    if (func_021BA040((int *)R(0x14)) == 0) {
        if (W(0x138)!=0 && func_021BB0E0(R(0x78))==0) {
            Vec v;
            Pos pos,delta={0,0};
            u32 out;
            Pos o1,o2;
            func_021BA3BC(R(0x38),&pos.x);
            mask=func_021BA3EC(R(0x38));
            if (pos.y<16 && (mask&0x40)) { delta.y-=4; moved=1; }
            if (pos.y<=168 && pos.y>136 && (mask&0x80)) { delta.y+=4; moved=1; }
            if (pos.x<16 && (mask&0x20)) { delta.x-=4; moved=1; }
            if (pos.x>240 && (mask&0x10)) { delta.x+=4; moved=1; }
            if (func_021BB0E0(R(0x78))==0 && func_021BB6AC(R(0xf4),&v,&out)) {
                delta.x=-(int)(((s64)v.x*4096+2048)>>12)>>12;
                delta.y=-(int)(((s64)v.y*4096+2048)>>12)>>12;
                func_021BB6DC(R(0xf4)); moved=1;
            }
            if (moved != 0) {
                func_021BA69C(R(0x50),&o1.x);
                func_021BB19C(R(0x78),(const u32 *)&delta);
                delta.x*=-1; delta.y*=-1;
                func_021BA6A8(R(0x50),&delta.x);
                func_021BA69C(R(0x50),&o2.x);
                func_021BA450(R(0x38),&o2.x);
            }
        }
        if (moved==0 && func_021BB0E0(R(0x78))==0) {
            if (*(int *)W(0x130)==0 || *(int *)W(0x130)==2) {
                w=func_021BA488(R(0x38));
                t=func_021BA6C8(R(0x50),R(0x38));
                if (w!=0 && w==t && func_021BA3E8(R(0x38))!=0 && func_021BA774((char *)w,12)!=0) {
                    *(int *)(W(0x130)+4)=2;
                    *(unsigned short *)(W(0x130)+8)=func_021BA774((char *)w,0);
                    *(int *)(W(0x130)+12)=func_021BA774((char *)w,13);
                    *(int *)(W(0x130)+16)=func_021BA774((char *)w,14);
                    func_020061E4(0x54c); func_021B995C(a,(int)func_021B99AC);
                }
            }
            if (func_020355C4()==0) t=1; else t=func_021BA3E8(R(0x38));
            if (t != 0) {
                w=func_021BA6C8(R(0x50),R(0x38));
                if (w!=W(0x134) && w!=0) {
                    Pos o3;
                    func_020061E4(0x548);
                    func_021BB220(R(0xb0),(void *)w); func_021BA7A4(R(0x50),(void *)w);
                    W(0x134)=w; func_021BA69C(R(0x50),&o3.x);
                    func_021BA3F4(R(0x38),w,(int *)(&o3));
                    if (W(0x138)==0) func_021BB5AC(R(0xd4),w);
                } else if (w==0 && W(0x134)!=0) {
                    func_021BB3D0(R(0xb0)); func_021BB5B4(R(0xd4),0); func_021BA7D4(R(0x50));
                    func_021BA3F4(R(0x38),0,0); W(0x134)=0;
                }
            }
        }
        if (W(0x138)!=0) func_021BB5B4(R(0xd4),0);
        func_021BA48C(R(0x38),moved ? 0 : 1);
    }
    func_021B9F50(R(0x14),R(0x78));
    if (func_021BB0E0(R(0x78))==0) func_021BA0E4(R(0x38),R(0x50));
    func_021BA5AC(R(0x50)); func_021BAFA8(R(0x78),R(0x50));
    func_021BB548(R(0xd4)); func_021BB5EC(R(0xf4));
    switch (func_021BA028(R(0x14))) {
    case 0:
        *(int *)(W(0x130)+4)=1; func_021B995C(a,(int)func_021B99AC); break;
    case 1:
        *(int *)(W(0x130)+4)=0; func_021B995C(a,(int)func_021B99AC); break;
    case 7:
        if (W(0x138)==0 && func_021BB0E0(R(0x78))==0) {
            Pos o4;
            func_021BA3BC(R(0x38),&o4.x);
            func_021BB0B4(R(0x78),8192,&d_021BBB78,&o4);
            func_020061E4(0x648);
            if (W(0x134)!=0) {
                func_021BB3D0(R(0xb0)); func_021BB5B4(R(0xd4),0); func_021BA7D4(R(0x50));
                func_021BA3F4(R(0x38),0,0); W(0x134)=0;
            }
            W(0x138)=1;
        } else if (W(0x138)==1 && func_021BB0E0(R(0x78))==0) {
            Pos o5;
            func_021BB190(R(0x78),&o5.x); o5.x+=128; o5.y+=96;
            func_021BB0B4(R(0x78),4096,&o5,&d_021BBB78);
            func_020061E4(0x649);
            if (W(0x134)!=0) {
                func_021BB3D0(R(0xb0)); func_021BB5B4(R(0xd4),0); func_021BA7D4(R(0x50));
                func_021BA3F4(R(0x38),0,0); W(0x134)=0;
            }
            W(0x138)=0;
        }
        break;
    }
    return func_021BB0DC(R(0x78));
}


void func_021B9E38(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap)
{
    Req r;
    Tbl t;
    Rect s;
    void *h;

    func_02082BCC(o, 0, 0x20);
    o[4] = s2;
    h = func_020490F4(0x55, heap);
    o[0] = func_0204AC18(h, 2, 0, 0, 0, 4, heap);
    o[1] = func_0204A6C8(h, 8, 0, 0, heap);
    o[2] = func_0204AF28(h, 0xc, 0x13, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    s.a = 0xa8;
    s.b = 0xa8;
    s.c = 7;
    o[5] = (u32)func_0204B294((void *)a2, o[1], o[0], o[2], &s, 0, heap);
    func_0204B92C((struct Obj *)o[5], 1);
    func_0204B974((struct Actor *)o[5]);
    t = d_021BBB8C;
    func_02082BCC(&r, 0, 0x20);
    r.f0 = (u8 *)&t;
    r.f4 = 2;
    r.f8 = a2;
    r.fC = a3;
    r.f10 = s0;
    r.f14 = s1 + 4;
    r.f18 = 2;
    o[3] = func_021B62E0(&r, heap);
    func_021B6520((u8 *)o[3], 10);
}

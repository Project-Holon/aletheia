/*
 * file:     game_beacon_search_p03.c
 * unit:     yes
 * function: func_021656F8, func_0216570C, func_02165730, func_0216573C, func_02165760, func_0216576C, func_02165794, func_021657B0, func_021657D8, func_021657E8, func_02165814, func_02165844, func_0216586C, func_02165888, func_021658D4, func_02165940, func_02165960, func_021659F0, func_02165A10, func_02165AC4, func_02165B04, func_02165B10, func_02165B2C, func_02165B5C, func_02165C10, func_02165C34, func_02165C48, func_02165C50, func_02165C58, func_02165C5C, func_02165C60
 * address:  0x021656F8
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
 *   func_0202744C 0x0202744C thumb
 *   func_02027060   0x02027060  thumb
 *   func_02026FB8   0x02026FB8  thumb
 *   g_02146940      0x02146940  data
 *   func_020270AC  0x020270AC  thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C20C 0x0200C20C thumb
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045A38  0x02045A38  arm
 *   func_0203F4CC 0x0203F4CC arm
 *   func_02026CA0 0x02026CA0 thumb
 *   func_02026C1C 0x02026C1C thumb
 *   func_02026CE0 0x02026CE0 thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *   func_02026D04   0x02026D04  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02030734 0x02030734 arm
 *   d_021729D4 0x021729D4 data a4
 *   func_02165FB4  0x02165FB4  thumb  ov010
 *   d_02171CA8     0x02171CA8  data
 *   func_02045994  0x02045994  arm
 *   func_0200E3A4  0x0200E3A4  thumb
 */
#include "../../matched/include/Obj00121.h"
#include "../../matched/include/Obj00121.h"
#include "../../matched/include/Obj18996.h"

struct Big;
struct Blk34;
struct RtcTime;
struct Queue;
struct Rec;
struct Strbuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Rec {
    u8 f00;
    u8 pad01[15];
    u16 f10;
    u8 pad12[0x46];
    u32 tail;
};

struct Queue {
    struct Rec r[30];
    u16 tag[30];
    u8 head;
    u8 count;
};

typedef struct Rec_02165B5C {
    u8 f00[3];
    u8 f03 : 7;         /* 0x03 */
    u8 f03_7 : 1;
    u32 f04_0 : 17;     /* 0x04 */
    u32 f04_17 : 10;
    u32 f04_27 : 5;
    u32 f08_0 : 17;     /* 0x08 */
    u32 f08_17 : 5;
    u32 f08_22 : 10;
    u32 f0C_0 : 9;      /* 0x0C */
    u32 f0C_9 : 3;
    u32 f0C_12 : 4;
    u32 f0C_16 : 10;
    u32 f0C_26 : 6;
    u8 pad10[0x30 - 0x10];
    u16 f30;            /* 0x30 kind */
    u8 pad32[0x48 - 0x32];
    u16 f48_0 : 8;      /* 0x48 */
    u16 f48_8 : 8;
} Rec_02165B5C;

typedef int (*RecCheck)(Rec_02165B5C *r);

typedef signed char s8;

typedef short s16;

typedef struct Rec_02165C34 {
    u8 pad00[0x12];
    u16 name[8];        /* 0x12 */
} Rec_02165C34;

typedef struct {
    u32 _pad0;
    u32 _pad1;
    u32 _pad2;
    u32 field : 6;
} S_02165C48;

typedef struct {
    u32 w0;
    u32 lo : 27;
    u32 hi : 5;
} S_02165C50;

extern int func_0202744C(void *);
extern u32 func_02027060(u32 a);
extern void func_02026FB8(void *);
extern int func_020270AC();
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *);
extern u16 *func_0200C20C(struct Blk34 *p);
extern void func_0201F41C(const u16 *,u16 *,u32);
extern int func_02045A38();
extern void func_0203F4CC(struct RtcTime *time);
extern int func_02026CA0(int *);
extern void *func_02026C1C(int n);
extern void func_02026CE0(u32 n);
extern void MI_CpuFill8(void *, u8, u32);
extern int func_02026D04(const struct Rec *r);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern int _s32_div_f(int a, int b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag);
void func_02165940(unsigned char *p);
int func_02165960(struct Queue *q, struct Rec *rec, int tag, int mode);
int func_021659F0(u8 *q, int delta);
int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag);
int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
u8 func_02165B04(u8 *q);
u8 *func_02165B10(u32 heap);
extern u8 func_02165FB4(u16 kind);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0200E3A4(const u8 *bits, int id);
u8 *func_02165B2C(u32 heap);
int func_02165B5C(Rec_02165B5C *r);
int func_02165C10(u8 *p);
void func_02165C34(Rec_02165C34 *r, void *buf);
u32 func_02165C48(S_02165C48 *a0);
u32 func_02165C50(S_02165C50 *a0);
u8 func_02165C58(const u8 *p);
u8 func_02165C5C(const u8 *p);
int func_02165C60(int a0);
void func_021656F8(u8 *p, u8 v);
void func_0216570C(void);
void func_02165730(void *a0);
void func_0216573C(void);
void func_02165760(void *a0);
void func_0216576C(void *a0);
int func_02165794(int a0, int a1);
void func_021657B0(u16 v);
void func_021657D8(void *a0, u16 a1);
void func_021657E8(void *a,u16 b);
void func_02165814(u8 *p,void *a,u16 b);
void func_02165844(void *v);
int func_0216586C(int a0, int a1);
int func_02165888(int a0);
extern char *g_02146940;
extern const char d_021729D4[];
extern const RecCheck d_02171CA8[];



void func_021656F8(u8 *p, u8 v) { ((struct Obj00121 *)p)->f30=0x2c; p[0x34]=v; func_0202744C(p); }




/*
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 */
void func_0216570C(void)
{
    if (func_02027060(0x2D)) {
        func_02165730(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}




/*
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 */
void func_02165730(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2D;
    func_0202744C(a0);
}




void func_0216573C(void)
{
    if (func_02027060(0x2E)) {
        func_02165760(g_02146940 + 4);
        func_02026FB8(g_02146940 + 4);
    }
}




void func_02165760(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x2E;
    func_0202744C(a0);
}




/*
 * Test id 0x2F against the overlay's table and, when it takes, file the
 * record at the shared globals pointer (sibling of func_02165634).
 */
void func_0216576C(void *a0)
{
    if (func_02027060(0x2F)) {
        func_02165794((int)(g_02146940 + 4), (int)a0);
        func_02026FB8(g_02146940 + 4);
    }
}








int func_02165794(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x2f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_021657A6:
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_021657AC:
    return a0;}







void func_021657B0(u16 v) { if(func_02027060(0x30)) { func_021657D8(g_02146940+4,v); func_02026FB8(g_02146940+4); } }








void func_021657D8(void *a0, u16 a1)
{
    ((struct Obj00121 *)a0)->f30 = 48;
    ((struct Obj00121 *)a0)->f34 = a1;
    func_0202744C(a0);
}







void func_021657E8(void *a,u16 b) { if(func_02027060(0x18)) { func_02165814((u8 *)g_02146940+4,a,b); func_02026FB8(g_02146940+4); } }





void func_02165814(u8 *p,void *a,u16 b) { func_0201F41C(func_0200C20C(func_0200C0F0(func_02012EBC(a))),(u16 *)(p+0x34),9); ((struct Obj00121 *)p)->f30=0x18; ((struct Obj00121 *)p)->f46=b; func_0202744C(p); }





void func_02165844(void *v) { if(func_02027060(0x31)) { func_0216586C((int)(g_02146940+4),(int)v); func_02026FB8(g_02146940+4); } }






int func_0216586C(int a0, int a1)
{
    int a2;
    int t4;

t4 = a0 + 0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
a2 = 9;
    a0 = func_02045A38(a0, a1, a2);
loc_0216587C:
a0 = 0x31;
((struct Obj00121 *)t4)->f30 = a0;
a0 = t4 + 0;
    a0 = func_0202744C((void *)a0);
loc_02165886:
    return a0;}





int func_02165888(int a0)
{
    int t[3];
    int cur;
    int n;
    int h;
    int k;
    int r;

    n = 0;
    cur = 0;
    func_0203F4CC((struct RtcTime *)t);
    h = (unsigned short)((t[0] << 8) | t[1]);
    for (;;) {
        k = func_02026CA0(&cur);
        if (k == 0x1e) {
            break;
        }
        r = func_02165960((struct Queue *)a0, (struct Rec *)((int)func_02026C1C(k)), h, 0);
        if (r == 0x1e) {
            break;
        }
        func_02026CE0(k);
        n++;
    }
    return n;
}





/*
 * Pops the front record of a 30-slot queue (0x5c-byte records, then a
 * u16 tag per slot at +0xAC8): copies out slot 0 and its tag, shifts the
 * rest down one and clears the last record. Returns 0 when empty.
 */
int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag)
{
    int i;

    if (q->r[0].f00 == 0)
        return 0;
    *out = q->r[0];
    *tag = q->tag[0];
    for (i = 1; i < 30; i++) {
        q->r[i - 1] = q->r[i];
        q->tag[i - 1] = q->tag[i];
    }
    MI_CpuFill8(&q->r[29], 0, 0x5c);
    return 1;
}


/*
 * Sweep the 0x5c-strided record array and hand the first occupied slot to
 * the arm9 helper; the sweep stops at the first empty one.
 */
void func_02165940(unsigned char *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        if (p[i * 0x5C] == 0)
            break;
        func_02026D04((const struct Rec *)(p + i * 0x5C));
    }
}


/*
 * Inserts a record into the 30-slot queue (see func_021658D4): reuses the
 * first empty slot or the slot with the same f10; otherwise, when the
 * mode is 1, drops slot 0 by shifting everything down and appends.
 * Returns the slot used, or 30 when full and mode is not 1.
 */
int func_02165960(struct Queue *q, struct Rec *rec, int tag, int mode)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (q->r[i].f00 == 0 || rec->f10 == q->r[i].f10) {
            q->r[i] = *rec;
            q->tag[i] = tag;
            return i;
        }
    }
    if (mode == 1) {
        MIi_CpuCopy32(&q->r[1], &q->r[0], 29 * 0x5c);
        MIi_CpuCopy16(&q->tag[1], &q->tag[0], 58);
        q->r[29] = *rec;
        q->tag[29] = tag;
        return 29;
    }
    return 30;
}


/*
 * Ring index of the 30-slot queue (func_021658D4): head byte at +0xB04
 * plus a signed offset, wrapped mod 30 (a negative offset is biased by
 * 30 first). Filed as the callee of 02165A10.
 */
int func_021659F0(u8 *q, int delta)
{
    int h = q[0xB04];

    if (delta < 0)
        return (h + delta + 30) % 30;
    return (h + delta) % 30;
}


/*
 * Ring-buffer variant of the queue insert (func_021659F0 maps a logical
 * index to a slot): replaces the record with the same f10 if present
 * before the first empty slot, else pushes a new head; the count byte
 * saturates at 30. *flag (optional) is 1 when a new slot was taken.
 */
int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag)
{
    int i;
    int idx;

    if (flag)
        *flag = 0;
    for (i = 0; i < 30; i++) {
        idx = func_021659F0((u8 *)q, i);
        if (q->r[idx].f00 == 0)
            break;
        if (rec->f10 == q->r[idx].f10) {
            q->r[idx] = *rec;
            q->tag[idx] = tag;
            return i;
        }
    }
    if (flag)
        *flag = 1;
    idx = func_021659F0((u8 *)q, -1);
    q->r[idx] = *rec;
    q->tag[idx] = tag;
    q->head = idx;
    if (q->count < 30)
        q->count++;
    return 0;
}


/*
 * Reads the record and tag at a ring offset from the head of the queue
 * (func_021659F0 maps the offset to a slot); returns 0 for an empty slot.
 *
 * Follower 0x02165B04 (ldrb accessor of the count byte) is unlabelled.
 */
int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta)
{
    int idx = func_021659F0((u8 *)q, delta);

    if (q->r[idx].f00 == 0)
        return 0;
    *out = q->r[idx];
    *tag = q->tag[idx];
    return 1;
}


/*
 * Count byte of the 30-record queue func_02165AC4 reads (head at +0xB04,
 * count at +0xB05). Unlabelled leaf reached from ov032 func_021F27D4.
 */
u8 func_02165B04(u8 *q)
{
    return q[0xb05];
}

u8 *func_02165B10(u32 heap) { return func_02030734(heap,0x5c,1,d_021729D4,0x1b3); }


u8 *func_02165B2C(u32 heap) { u8 *p=func_02030734(heap,0xb08,1,d_021729D4,0x1c1); p[0xb04]=0; p[0xb05]=0; return p; }



/*
 * Range check of a packed record: returns 1 (invalid) on the first field
 * out of range, else the verdict of the per-kind checker picked from
 * the table at 0x02171CA8 by func_02165FB4(kind).
 */
int func_02165B5C(Rec_02165B5C *r)
{
    if (r->f30 == 0 || r->f30 >= 0x33)
        return 1;
    if (r->f48_0 >= 6)
        return 1;
    if (r->f0C_9 >= 6)
        return 1;
    if (r->f0C_16 > 999 || r->f0C_26 > 59)
        return 1;
    if (r->f03 > 0x2D && r->f03 != 0x30)
        return 1;
    if (r->f04_17 >= 427 || r->f08_22 >= 427)
        return 1;
    if (r->f04_0 > 99999 || r->f08_0 > 99999)
        return 1;
    if (d_02171CA8[func_02165FB4(r->f30)](r) != 0)
        return 1;
    return 0;
}



int func_02165C10(u8 *p)
{
    switch (((struct Obj18996 *)p)->f30) {
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x32:
        return 1;
    }
    return 0;
}



/*
 * Copy the eight-character name at +0x12 into a string buffer.
 */
void func_02165C34(Rec_02165C34 *r, void *buf)
{
    func_02045994(buf, r->name, 8);
}



/*
 * Recursive MATCH unblocker: callee of func_021BCDC0 (ov216) +0002. Coherent
 * Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes that site
 * attest as `matched`.
 */
u32 func_02165C48(S_02165C48 *a0)
{
    return a0->field;
}



/*
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov011 func_02173368 +00CA: returns the top five bits of the second
 * word of its argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02165C50(S_02165C50 *a0)
{
    return a0->hi;
}


/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 4B getter 02165C5C, separately owned and filed.
 */
u8 func_02165C58(const u8 *p) { return p[1]; }


/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
u8 func_02165C5C(const u8 *p) { return p[2]; }



int func_02165C60(int a0)
{
    int a1;

a0 = a0 + 0x50;
a1 = 0x1a;
    a0 = func_0200E3A4((const u8 *)a0, a1);
loc_02165C6A:
    if (a0 != 0) goto loc_02165C72;
loc_02165C6E:
a0 = 0xff;
    return a0;
loc_02165C72:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}

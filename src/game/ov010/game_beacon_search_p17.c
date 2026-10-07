/*
 * file:     game_beacon_search_p17.c
 * unit:     yes
 * function: func_02165888, func_021658D4, func_02165940, func_02165960, func_021659F0, func_02165A10, func_02165AC4, func_02165B04, func_02165B10
 * address:  0x02165888
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
 */
struct RtcTime;
struct Queue;
struct Rec;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

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

extern void func_0203F4CC(struct RtcTime *time);
extern int func_02026CA0(int *);
extern void *func_02026C1C(int n);
extern void func_02026CE0(u32 n);
extern void MI_CpuFill8(void *dst, u32 v, u32 size);
extern int func_02026D04(const struct Rec *r);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern int _s32_div_f(int a, int b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_02165888(int a0);
int func_021658D4(struct Queue *q, struct Rec *out, u16 *tag);
void func_02165940(unsigned char *p);
int func_02165960(struct Queue *q, struct Rec *rec, int tag, int mode);
int func_021659F0(u8 *q, int delta);
int func_02165A10(struct Queue *q, struct Rec *rec, u16 tag, int *flag);
int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
u8 func_02165B04(u8 *q);
u8 *func_02165B10(u32 heap);
extern const char d_021729D4[];


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

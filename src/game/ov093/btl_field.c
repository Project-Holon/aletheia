/*
 * file:     btl_field.c
 * unit:     yes
 * function: func_021EF83C, func_021EF874, func_021EF884, func_021EF894, DWC_StartUtilityEx, func_021EF8B8, func_021EF8C8, func_021EF8E8, func_021EF8F8, func_021EF90C, SetBottomScreenLineCentered, func_021EF934, func_021EF948, func_021EF958, func_021EF980, func_021EF988, func_021EF9A8, func_021EF9B0, func_021EF9C0, func_021EF9C8, func_021EF9D0, func_021EF9F4
 * address:  0x021EF83C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06898020  0x06898020  thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021ECEB8  0x021ECEB8  thumb  ov093
 *   func_021ECF68   0x021ECF68  thumb  ov093
 *   func_0204E720  0x0204E720  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_021EB318  0x021EB318  thumb  ov093
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045374 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02040618 0x02040618 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021D590C  0x021D590C  thumb  ov093
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_02041300  0x02041300  arm
 *   func_02030734  0x02030734  arm
 *   d_021F3ADC  0x021F3ADC  data  a4
 *   func_020307B0   0x020307B0  arm arm9
 *   func_02082D44  0x02082D44  arm
 *   func_021D8470  0x021D8470  thumb
 *   func_021D845C  0x021D845C  thumb
 *   d_021F6388  0x021F6388  data  a4
 *   d_021F6384  0x021F6384  data  a4
 *   sub_02030734   0x02030734  arm
 *   d_021F3AE8     0x021F3AE8  data  ov093  a4
 *   func_021D4C58   0x021D4C58  thumb
 *   func_021D4B58  0x021D4B58  thumb  ov093
 *   func_021D4B98  0x021D4B98  thumb  ov093
 *   func_021D4BD4  0x021D4BD4  thumb  ov093
 *   func_021D4C60  0x021D4C60  thumb  ov093
 *   func_021D4C6C  0x021D4C6C  thumb  ov093
 *   func_021D4C84  0x021D4C84  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F63D8     0x021F63D8  data  ov093  a4
 *   d_021F3990     0x021F3990  data  ov093  a2
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_0201EE84  0x0201EE84  thumb
 *   func_021BA020  0x021BA020  thumb  ov093
 *   func_0201F0F8  0x0201F0F8  thumb
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021B9FAC  0x021B9FAC  thumb  ov093
 *   func_021BA064  0x021BA064  thumb  ov093
 *   func_021BA080  0x021BA080  thumb  ov093
 *   func_0202A3CC  0x0202A3CC  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F134  0x0201F134  thumb
 *   d_021F63C8     0x021F63C8  data  a4
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 *   d_021F39A0     0x021F39A0  data  a2
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F39D8  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   func_02045A98  0x02045A98  arm
 *   func_0201D5C4  0x0201D5C4  thumb
 *   func_0201D5CC  0x0201D5CC  thumb
 *   func_0201D670  0x0201D670  thumb
 *   func_0201D5F4  0x0201D5F4  thumb
 *   func_0201D658  0x0201D658  thumb
 *   func_0201D688  0x0201D688  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201F020 0x0201F020 thumb
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021E8918  0x021E8918  thumb  ov093
 *   d_021F63F4  0x021F63F4  data  a4
 *   func_021EFA94  0x021EFA94  thumb  ov093
 *   func_021EFAD8  0x021EFAD8  thumb  ov093
 *   func_021EFB34  0x021EFB34  thumb  ov093
 *   func_021EFC1C  0x021EFC1C  thumb  ov093
 *   func_021EFC78  0x021EFC78  thumb  ov093
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   d_021F3AF8  0x021F3AF8  data  a4
 *   func_021E8A98  0x021E8A98  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* One word passed by value (the caller pushes r0-r3 as a frame). */
typedef struct { u32 word; } BtlFieldSlotKey;

/* Armed timer: while value is set and count is not 0xff, count steps down;
 * at zero the value is returned and cleared. */
typedef struct {
    u32 value;
    u32 count;
} BtlFieldCountdown;

/* Eight-slot table: one u32[8] array per property plus a u32[8][6] block,
 * all indexed by the slot number.  Written as member arrays, the load of
 * used[slot] keeps slot*4 in its own register while the other stores
 * recompute base + slot*4 (raw `*(u32 *)(a + K + slot * 4)` casts CSE'd
 * slot*4 and swapped the registers). */
typedef struct {
    BtlFieldCountdown countdown;    /* 0x000 */
    u32 handle[8];                  /* 0x008 */
    BtlFieldSlotKey key[8];         /* 0x028 */
    u32 progress[8];                /* 0x048 */
    u32 stats[8][6];                /* 0x068 */
    u32 pending[8];                 /* 0x128 */
    u32 used[8];                    /* 0x148 */
} BtlFieldState;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_06898020(u32 slot, int arg);
extern BtlFieldSlotKey func_021E8918(void);
extern u32 func_021E8A98(BtlFieldSlotKey key);
extern int func_021EFA94(BtlFieldState *state, int arg);
extern int func_021EFAD8(BtlFieldState *state, u32 slot, u32 value);
extern int func_021EFB34(BtlFieldState *state, int arg);
extern void func_021EFC1C(BtlFieldState *state, int line, int color, char *text);
extern int func_021EFC78(BtlFieldState *state, int arg0, int arg1);
extern void *func_021EFCE4(BtlFieldState *state, int arg);
void func_021EF988(BtlFieldState *state, u32 value);
u8 func_021EF9A8(BtlFieldCountdown *countdown);
int func_021EF9B0(BtlFieldCountdown *countdown);
int *func_021EF9C0(int *countdown, int value, int count);
u32 func_021EF9D0(BtlFieldCountdown *countdown);
int func_021EF9F4(BtlFieldState *state, u32 slot, BtlFieldSlotKey key, int allocHandle);
void func_021EF83C(BtlFieldState *state, u32 slot);
extern BtlFieldState d_021F63F4;
extern char d_021F3AF8[];


void func_021EF83C(BtlFieldState *state, u32 slot)
{
    u32 j;

    state->handle[slot] = 0;
    state->key[slot] = func_021E8918();
    state->progress[slot] = 0;
    state->pending[slot] = 0;
    state->used[slot] = 0;
    for (j = 0; j < 6; j++)
        state->stats[slot][j] = 0x1f;
}


void func_021EF874(int value)
{
    func_021EF988(&d_021F63F4, value);
}


int func_021EF884(void)
{
    return func_021EF9A8(&d_021F63F4.countdown);
}


int func_021EF894(void)
{
    return func_021EF9B0(&d_021F63F4.countdown);
}


int DWC_StartUtilityEx(int value, int count)
{
    return (int)func_021EF9C0((int *)&d_021F63F4.countdown, value, count);
}


/*
 * Tail call into the countdown step with the static state.
 */
u32 func_021EF8B8(void)
{
    return func_021EF9D0(&d_021F63F4.countdown);
}


int func_021EF8C8(u32 slot, BtlFieldSlotKey key)
{
    return func_021EF9F4(&d_021F63F4, slot, key, 1);
}


int func_021EF8E8(int arg)
{
    return func_021EFA94(&d_021F63F4, arg);
}


int func_021EF8F8(int slot, int value)
{
    return func_021EFAD8(&d_021F63F4, slot, value);
}


int func_021EF90C(int arg)
{
    return func_021EFB34(&d_021F63F4, arg);
}


void SetBottomScreenLineCentered(int line, int color, char *text)
{
    func_021EFC1C(&d_021F63F4, line, color, text);
}


int func_021EF934(int arg0, int arg1)
{
    return func_021EFC78(&d_021F63F4, arg0, arg1);
}


int func_021EF948(int arg)
{
    return (int)func_021EFCE4(&d_021F63F4, arg);
}


BtlFieldState *func_021EF958(u32 heapId)
{
    BtlFieldState *state = func_02030734(heapId, 0x168, 1, d_021F3AF8, 0x10c);

    func_021EF988(state, 0);
    return state;
}


void func_021EF980(void *state) { func_020307B0(state); }


void func_021EF988(BtlFieldState *state, u32 value)
{
    u32 i;

    for (i = 0; i < 8; i++)
        func_021EF83C(state, i);
    state->countdown.value = value;
    state->countdown.count = 0xff;
}


u8 func_021EF9A8(BtlFieldCountdown *countdown) { return (u8)countdown->value; }


int func_021EF9B0(BtlFieldCountdown *countdown)
{
    if (countdown->value != 0)
        return countdown->count;
    return 0;
}


int *func_021EF9C0(int *countdown, int value, int count)
{
    countdown[0] = value;
    countdown[1] = count;
    return countdown;
}


void func_021EF9C8(int *countdown)
{
    countdown[0] = 0;
    countdown[1] = 0;
}


/*
 * Countdown timer: when the value is set and the counter is not 0xff,
 * decrement the counter; when it reaches zero, clear the value and return
 * its low byte.
 */
u32 func_021EF9D0(BtlFieldCountdown *countdown)
{
    u32 v = countdown->value;
    if (v != 0 && countdown->count != 0xff && --countdown->count == 0) {
        v = (u8)v;
        countdown->value = 0;
        return v;
    }
    return 0;
}


int func_021EF9F4(BtlFieldState *state, u32 slot, BtlFieldSlotKey key, int allocHandle)
{
    u32 i;
    u32 stat;

    if (state->used[slot] == 0) {
        if (allocHandle != 0) {
            state->handle[slot] = func_06898020(slot, 0);
            if (state->handle[slot] == 0)
                return 0;
        }
        state->used[slot] = 1;
        state->key[slot] = key;
        state->progress[slot] = 0;
        state->pending[slot] = 0;
        for (i = 0; i < 6; i++)
            state->stats[slot][i] = 0x1f;
        stat = func_021E8A98(key);
        if (stat != 0x1f)
            func_021EFAD8(state, slot, stat);
        return 1;
    }
    return 0;
}

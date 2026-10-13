/*
 * file:     unit_021EE104.c
 * unit:     yes
 * function: func_021EE104, func_021EE200, func_021EE21C, func_021EE224, func_021EE228, func_021EE23C, func_021EE25C, func_021EE264, func_021EE2A0, func_021EE2F8, func_021EE318, func_021EE370, func_021EE390, func_021EE3E8, func_021EE4B4, func_021EE544
 * address:  0x021EE104
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
 *   func_021EF694  0x021EF694  thumb
 *   func_021EF71C  0x021EF71C  thumb
 *   func_021EF7AC  0x021EF7AC  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct BmpWin BmpWin;
typedef struct TextCanvas TextCanvas;

/* Battle work as far as this file reads it. */
typedef struct {
    u8 reserved00[0x34];
    u32 textBuf;            /* 0x34 */
    u8 reserved38[0x100];
    void *partyLists;       /* 0x138 */
} BtlvScuWork;

/* Ball state shown for each party member: 0 empty, 1 healthy, 2 fainted,
 * 3 status ailment. */
typedef struct {
    u16 sideFlag;
    u16 ball[6];
} BtlvBallStates;

typedef struct BtlvBallWindow BtlvBallWindow;
typedef int (*BtlvBallWindowStep)(int *state, BtlvBallWindow *window);

/* Task that shows, refreshes and closes the party ball window; a
 * two-slot runner: pendingStep runs first, then currentStep. */
struct BtlvBallWindow {
    u8 reserved00[8];
    BmpWin *window;                 /* 0x08 */
    TextCanvas *canvas;             /* 0x0c */
    u32 frameBase;                  /* 0x10 */
    u8 reserved14[0x10];
    void *drawParam;                /* 0x24 */
    u8 reserved28[0xc];
    u32 textBuf;                    /* 0x34 */
    u8 reserved38[0xa8];
    BtlvBallWindowStep pendingStep; /* 0xe0 */
    BtlvBallWindowStep currentStep; /* 0xe4 */
    BtlvBallWindow *stepArg;        /* 0xe8 */
    int stepState;                  /* 0xec */
    u8 reservedF0[0x7c];
    void **partySource;             /* 0x16c */
    BtlvBallStates states;          /* 0x170 */
};

/* Window and canvas pair cleared together. */
typedef struct {
    BmpWin *window;
    TextCanvas *canvas;
} BtlvWaitWindow;

extern void func_02082BCC(void *dst, u8 value, u32 size);
extern void *func_021B9AF8(void *partyLists, int clientIndex);
extern u8 func_021B9B94(void *party);
extern void *func_021B9C00(void *party, u32 index);
extern int func_021D5B68(void *mon);
extern int func_021D62A8(void *mon);
extern int func_021D5B7C(void *mon);
extern void func_021ECEB8(BtlvScuWork *work, u32 textBuf, u16 arg2, u32 arg3);
extern int func_021ECF68(void *work);
extern void func_0204E720(u32 mode, s32 start, s32 end, s32 wait);
extern void func_02043B5C(TextCanvas *canvas, u8 color);
extern void func_02045334(BmpWin *window);
extern u32 func_021EB318(void);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_02045374(BmpWin *window);
extern void BMP_WIN_DrawFrame(BmpWin *window, u16 base, u32 pal);
extern u8 func_02045730(BmpWin *window);
extern void func_020409B4(u32 index);
extern void func_0201C7A4(void *canvas, s16 x, s16 y, void *textBuf, void *drawParam);
extern void func_02040618(u32 layer, u32 arg1, u32 arg2);
extern void func_020061E4(u32 soundId);
extern void func_021D590C(void **source, u16 *out);
extern u8 func_02045738(BmpWin *window);
extern u8 func_02045740(BmpWin *window);
extern u8 func_02045758(BmpWin *window);
extern u8 func_02045760(BmpWin *window);
extern void func_02041300(u32 index, u32 arg1, u32 left, u32 top, u8 width, u8 height, u8 fill);
void func_021EF694(u32 textBuf, u32 msgId);
void func_021EF71C(u32 textBuf, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_021EF7AC(u32 textBuf, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
int func_021EE3E8(int *state, BtlvBallWindow *window);
int func_021EE4B4(int *state, BtlvBallWindow *window);
int func_021EE544(int *state, BtlvBallWindow *window);


/*
 * tail: 021EE1FE..021EE200 is zero alignment padding.
 */
void func_021EE104(BtlvScuWork *work, u32 *outStates, u32 clientA, u32 clientB, u32 sideFlag)
{
    void *partyLists[2] = {0, 0};
    int partyCounts[2] = {0, 0};
    int i;
    int side;
    s8 slot;
    void *mon;
    func_02082BCC(outStates, 0, 28);
    partyLists[0] = func_021B9AF8(work->partyLists, clientA);
    partyCounts[0] = func_021B9B94(partyLists[0]);
    if (clientB < 4) {
        partyLists[1] = func_021B9AF8(work->partyLists, clientB);
        partyCounts[1] = func_021B9B94(partyLists[1]);
        if (partyCounts[0] > 3) partyCounts[0] = 3;
        if (partyCounts[1] > 3) partyCounts[1] = 3;
    }
    outStates[0] = sideFlag;
    for (i = 0; i < 6; i++) {
        if (i < partyCounts[0] + partyCounts[1]) {
            if (i < partyCounts[0]) { side = 0; slot = i; }
            else { side = 1; slot = i - partyCounts[0]; }
            mon = func_021B9C00(partyLists[side], (u8)slot);
            if (func_021D5B68(mon)) outStates[side * 3 + slot + 1] = 2;
            else if (func_021D62A8(mon)) outStates[side * 3 + slot + 1] = 3;
            else if (!func_021D5B7C(mon)) outStates[side * 3 + slot + 1] = 0;
            else outStates[side * 3 + slot + 1] = 1;
        }
    }
}


void func_021EE200(BtlvScuWork *work)
{
    func_021EF694(work->textBuf, 0xf);
    func_021ECEB8(work, work->textBuf, 0, 0);
}


/*
 * Untraced mid-stream entry point: a plain tail thunk, `ldr r3,=T; bx r3`, whose pool word names func_021ECF68.
 */
int func_021EE21C(BtlvScuWork *work) { return func_021ECF68(work); }


void func_021EE224(char *unused)
{
}


void func_021EE228(void)
{
    int x = 0x10;
    func_0204E720(1, 0, x, x - 0x13);
}


void func_021EE23C(BtlvWaitWindow *waitWindow)
{
    func_02043B5C(waitWindow->canvas, 12);
    func_02045334(waitWindow->window);
    func_0204E720(1, 16, 0, -3);
}


int func_021EE25C(void)
{
    return func_021EB318();
}


void func_021EE264(BtlvBallWindow *window, int partySource, BtlvBallStates *states)
{
    window->partySource = (void **)partySource;
    window->states = *states;
    window->pendingStep = 0;
    window->currentStep = func_021EE3E8;
    window->stepArg = window;
    window->stepState = 0;
}


int func_021EE2A0(BtlvBallWindow *window)
{
    if (window->pendingStep != 0) {
        if (window->pendingStep(&window->stepState, window->stepArg) != 0) {
            window->pendingStep = 0;
            window->stepState = 0;
        }
        return 0;
    }
    if (window->currentStep != 0) {
        if (window->currentStep(&window->stepState, window->stepArg) != 0) {
            window->currentStep = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void func_021EE2F8(BtlvBallWindow *window)
{
    window->pendingStep = 0;
    window->currentStep = func_021EE4B4;
    window->stepArg = window;
    window->stepState = 0;
}


int func_021EE318(BtlvBallWindow *window)
{
    if (window->pendingStep != 0) {
        if (window->pendingStep(&window->stepState, window->stepArg) != 0) {
            window->pendingStep = 0;
            window->stepState = 0;
        }
        return 0;
    }
    if (window->currentStep != 0) {
        if (window->currentStep(&window->stepState, window->stepArg) != 0) {
            window->currentStep = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


void func_021EE370(BtlvBallWindow *window)
{
    window->pendingStep = 0;
    window->currentStep = func_021EE544;
    window->stepArg = window;
    window->stepState = 0;
}


int func_021EE390(BtlvBallWindow *window)
{
    if (window->pendingStep != 0) {
        if (window->pendingStep(&window->stepState, window->stepArg) != 0) {
            window->pendingStep = 0;
            window->stepState = 0;
        }
        return 0;
    }
    if (window->currentStep != 0) {
        if (window->currentStep(&window->stepState, window->stepArg) != 0) {
            window->currentStep = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}


int func_021EE3E8(int *state, BtlvBallWindow *window)
{
    switch (*state) {
    case 0:
        func_0201DD78(1, 9, 12);
        func_02045374(window->window);
        BMP_WIN_DrawFrame(window->window, window->frameBase, 3);
        func_02043B5C(window->canvas, 12);
        func_020409B4(func_02045730(window->window));
        (*state)++;
        break;
    case 1:
        func_021EF71C(window->textBuf, window->states.ball[0], window->states.ball[1], window->states.ball[2], window->states.ball[3], window->states.ball[4], window->states.ball[5]);
        func_0201C7A4(window->canvas, 0, 0, (void *)window->textBuf, window->drawParam);
        (*state)++;
        break;
    case 2:
        func_02045334(window->window);
        (*state)++;
        break;
    case 3:
        func_02040618(3, 0, 0);
        func_02040618(3, 3, 0x100);
        func_020061E4(0x547);
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_021EE4B4(int *state, BtlvBallWindow *window)
{
    switch (*state) {
    case 0:
        func_021D590C(window->partySource, &window->states.sideFlag);
        func_021EF7AC(window->textBuf, window->states.ball[0], window->states.ball[1], window->states.ball[2], window->states.ball[3], window->states.ball[4], window->states.ball[5]);
        func_02043B5C(window->canvas, 12);
        func_0201C7A4(window->canvas, 0, 0, (void *)window->textBuf, window->drawParam);
        (*state)++;
        break;
    case 1:
        func_02045334(window->window);
        func_020061E4(0x547);
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


int func_021EE544(int *state, BtlvBallWindow *window)
{
    int left;
    int top;
    int width;
    int height;
    u8 index;

    switch (*state) {
    case 0:
        left = func_02045758(window->window) - 1;
        top = func_02045760(window->window) - 1;
        width = func_02045738(window->window) + 2;
        height = func_02045740(window->window) + 2;
        index = func_02045730(window->window);
        func_02041300(index, 0, (u8)left, (u8)top, (u8)width, (u8)height, 0);
        func_020409B4(index);
        func_020061E4(0x547);
        (*state)++;
        break;
    case 1:
        func_02040618(3, 0, -0x90);
        func_02040618(3, 3, 0);
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}

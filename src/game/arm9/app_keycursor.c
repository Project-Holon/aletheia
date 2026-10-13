/*
 * file:     app_keycursor.c
 * unit:     yes
 * function: APP_KEYCURSOR_Create, APP_KEYCURSOR_Delete, APP_KEYCURSOR_DrawMark, APP_KEYCURSOR_Animate, APP_KEYCURSOR_Update, func_02028748, func_02028754, PLAYER_VOLUME_FADER_Create, PLAYER_VOLUME_FADER_Delete, PLAYER_VOLUME_FADER_Update, PLAYER_VOLUME_FADER_SetTarget, PLAYER_VOLUME_FADER_SetMute, PLAYER_VOLUME_FADER_Init, PLAYER_VOLUME_FADER_StartFade, PLAYER_VOLUME_FADER_SetLevel, PLAYER_VOLUME_FADER_Tick, PLAYER_VOLUME_FADER_GetLevel, PLAYER_VOLUME_FADER_Apply
 * address:  0x020285A4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   BMP_CreateFromBuffer      0x020436FC  arm
 *   app_keycursor_File 0x020A74F0  data
 *   player_volume_fader_File 0x020A7500  data
 *   BMP_Delete  0x020437AC  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   BMP_Blit  0x020439A0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   PRINTSYS_PrintStreamGetState   0x0201CE30  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020307B0  0x020307B0  arm
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Bmp {
    void *pixels;
    u16   width;
    u16   height;
    u16   depth;
    u16   kind;
};

/* Cursor work: one 2x2-tile bitmap and the blink state of one text cursor. */
struct KeyCursor {
    struct Bmp *item;  /* 0x00 */
    u8   phase;        /* 0x04 */
    u8   tick;         /* 0x05 */
    u8   held;         /* 0x06 */
    u8   live : 1;     /* 0x07 bit 0 */
    u8   flip : 1;     /* 0x07 bit 1 */
    u16  id;           /* 0x08 */
};

/* Flag word at 0x14 of an object defined elsewhere (see misplaced notes). */
struct Obj {
    u8  pad_00[0x14];
    u32 flags;
};

/* Nine bytes of mixer state: channel, current and target level, fade length
 * and elapsed frames, mute. */
struct Fader {
    u8  channel;
    u8  from;
    u8  to;
    u8  pad03;
    u16 frames;
    u16 elapsed;
    u8  mute;
};

struct Descriptor;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Delete(struct Bmp *bmp);
extern u16  BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void BMP_FillRect(const struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void BMP_Blit(struct Bmp *dst, const struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern u32   PRINTSYS_PrintStreamGetState(void *p);
extern u32   KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void NNS_SndPlayerSetPlayerVolume(u32 channel, u32 level);
struct KeyCursor *APP_KEYCURSOR_Create(u16 id, u32 live, u32 flip, u16 heap, void *pixels);
void APP_KEYCURSOR_Delete(struct KeyCursor *k);
void APP_KEYCURSOR_DrawMark(struct KeyCursor *k, const struct Bmp *bmp, u32 color);
void APP_KEYCURSOR_Animate(struct KeyCursor *k, const struct Bmp *bmp, u32 color);
void APP_KEYCURSOR_Update(struct KeyCursor *k, void *p, void *cell);
void func_02028748(struct Obj *obj, int n, int mask);
u32 func_02028754(struct Obj *obj, u32 n);
struct Fader *PLAYER_VOLUME_FADER_Create(void *a, int v);
void PLAYER_VOLUME_FADER_Delete(void *ptr);
void PLAYER_VOLUME_FADER_Update(struct Fader *s);
void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames);
void PLAYER_VOLUME_FADER_SetMute(struct Fader *s, u8 mute);
void PLAYER_VOLUME_FADER_Init(struct Fader *s);
void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames);
void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level);
void PLAYER_VOLUME_FADER_Tick(struct Fader *s);
u32 PLAYER_VOLUME_FADER_GetLevel(struct Fader *s);
void PLAYER_VOLUME_FADER_Apply(struct Fader *s);
extern const char app_keycursor_File[];
extern const char player_volume_fader_File[];

/*
 * TU: app_keycursor.c (__FILE__ 0x020A74F0, line 149).
 */
struct KeyCursor *APP_KEYCURSOR_Create(u16 id, u32 live, u32 flip, u16 heap,
                                void *pixels)
{
    struct KeyCursor *k;

    k = func_02030734(heap, sizeof(struct KeyCursor), 1, app_keycursor_File,
                      149);

    k->id = id;
    k->live = live;
    k->flip = flip;
    k->item = BMP_CreateFromBuffer(pixels, 2, 2, 0x20, heap);

    return k;
}


void APP_KEYCURSOR_Delete(struct KeyCursor *k)
{
    BMP_Delete(k->item);
    func_020307B0(k);
}


void APP_KEYCURSOR_DrawMark(struct KeyCursor *k, const struct Bmp *bmp, u32 color)
{
    u16 w = BMP_GetWidth(bmp) - 11;
    u16 h = BMP_GetHeight(bmp) - 9;

    BMP_FillRect(bmp, (s16)w, (s16)(h + k->phase), 0xa, 7, (u8)color);
}


void APP_KEYCURSOR_Animate(struct KeyCursor *k, const struct Bmp *bmp, u32 color)
{
    u16 w;
    u16 h;

    APP_KEYCURSOR_DrawMark(k, bmp, color);

    k->tick = k->tick + 1;
    if (k->tick >= 8) {
        k->tick = 0;
        k->phase = k->phase + 1;
        k->phase = (s32)k->phase % 3;
    }

    w = BMP_GetWidth(bmp) - 11;
    h = BMP_GetHeight(bmp) - 9;

    BMP_Blit(k->item, bmp, 0, 2, w, h + k->phase, 0xa, 7, 0);
}


void APP_KEYCURSOR_Update(struct KeyCursor *k, void *p, void *cell)
{
    u32 mode = PRINTSYS_PrintStreamGetState(p);

    switch (mode) {
    case 2:
        k->held = 0;
        return;
    case 1:
    {
        u32 r = 0;

        if (k->live) {
            r = KEY_GetTrg() & 3;
        }
        if (r == 0) {
            if (k->flip) {
                r = TOUCHPANEL_GetTrg();
            }
        }
        if (r != 0) {
            k->held = 1;
            APP_KEYCURSOR_DrawMark(k, BMP_WIN_GetBmp(cell), k->id);
            BMP_WIN_TransferChars(cell);
            return;
        }
        if (k->held != 0) {
            return;
        }
        APP_KEYCURSOR_Animate(k, BMP_WIN_GetBmp(cell), k->id);
        BMP_WIN_TransferChars(cell);
        return;
    }
    case 0:
        k->held = 0;
        return;
    }
}


/*
 * A pair of leaf accessors over a 32-bit flag word at offset 0x14: or
 * `mask << n` into it, and test bit `n`.  Neither calls anything.
 */
void func_02028748(struct Obj *obj, int n, int mask)
{
    obj->flags = obj->flags | (mask << n);
}


u32 func_02028754(struct Obj *obj, u32 n)
{
    return (obj->flags >> n) & 1;
}


/*
 * TU: player_volume_fader.c (__FILE__ 0x020A7500, line 66).
 *
 * The file is a nine byte record holding a channel id, a start and a target
 * level, a duration and an elapsed count, and the entry points that drive it.
 * PLAYER_VOLUME_FADER_GetLevel is the interpolation, PLAYER_VOLUME_FADER_Apply is the "push the current
 * level at the mixer" step every mutator ends with, and PLAYER_VOLUME_FADER_Tick is the
 * per-frame tick.  The division in PLAYER_VOLUME_FADER_GetLevel is the compiler's signed
 * helper (0x0209C0A4), so the operands are `int` and not unsigned.  Its four
 * locals need their declaration order and their initialisation order to
 * disagree (declaration order picks the registers, initialisation order picks
 * the load order).
 */
struct Fader *PLAYER_VOLUME_FADER_Create(void *a, int v)
{
    struct Fader *p = func_02030734((unsigned int)a, sizeof(struct Fader), 0,
                                    player_volume_fader_File, 0x42);
    PLAYER_VOLUME_FADER_Init(p);
    p->channel = v;
    return p;
}


void PLAYER_VOLUME_FADER_Delete(void *ptr)
{
    func_020307B0(ptr);
}


void PLAYER_VOLUME_FADER_Update(struct Fader *s)
{
    PLAYER_VOLUME_FADER_Tick(s);
}


void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames)
{
    if (frames == 0) {
        PLAYER_VOLUME_FADER_SetLevel(s, level);
    } else {
        PLAYER_VOLUME_FADER_StartFade(s, level, frames);
    }
}


void PLAYER_VOLUME_FADER_SetMute(struct Fader *s, u8 mute)
{
    s->mute = mute;
    PLAYER_VOLUME_FADER_Apply(s);
}


void PLAYER_VOLUME_FADER_Init(struct Fader *s)
{
    s->channel = 0;
    s->from = 0x7F;
    s->to = 0x7F;
    s->frames = 0;
    s->elapsed = 0;
    s->mute = 0;
    PLAYER_VOLUME_FADER_Apply(s);
}


void PLAYER_VOLUME_FADER_StartFade(struct Fader *s, u8 target, u16 frames)
{
    s->from = PLAYER_VOLUME_FADER_GetLevel(s);
    s->to = target;
    s->frames = frames;
    s->elapsed = 0;
}


void PLAYER_VOLUME_FADER_SetLevel(struct Fader *s, u8 level)
{
    s->from = level;
    s->to = level;
    s->frames = 0;
    s->elapsed = 0;
    PLAYER_VOLUME_FADER_Apply(s);
}


void PLAYER_VOLUME_FADER_Tick(struct Fader *s)
{
    if (s->elapsed < s->frames) {
        s->elapsed = s->elapsed + 1;
        PLAYER_VOLUME_FADER_Apply(s);
    }
}


u32 PLAYER_VOLUME_FADER_GetLevel(struct Fader *s)
{
    u16 elapsed;
    u8 from;
    u8 to;
    u16 frames;
    u32 level;

    from = s->from;
    to = s->to;
    elapsed = s->elapsed;
    frames = s->frames;
    level = from;
    if (elapsed != 0) {
        level = from + (to - from) * elapsed / frames;
    }
    return level;
}


void PLAYER_VOLUME_FADER_Apply(struct Fader *s)
{
    u32 level = PLAYER_VOLUME_FADER_GetLevel(s);

    if (s->mute != 0) {
        level = 0;
    }
    NNS_SndPlayerSetPlayerVolume(s->channel, level);
}

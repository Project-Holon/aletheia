/*
 * function: CommonCallback
 * address:  0x027049B0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02734450  0x02734450  data twl
 *   CheckState  0x02704C5C  arm twl
 *   ReplyCallback  0x02704CC4  arm twl
 *   SetSndexWork  0x02704D48  arm twl
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef void (*Cb)(u32, void *);

typedef struct {
    u32 pad0;
    u32 busy;
    u32 pad8;
    volatile u32 state;
    u32 pad10;
    u32 pad14;
    u32 f18;
    void (*f1c)(void);
    u32 f20;
    u32 pad24;
    u32 pad28;
    Cb f2c;
    void *f30;
    u32 pad34;
    u32 pad38;
    void (*f3c)(void);
    u32 f40;
    u32 pad44;
    u32 pad48;
    Cb f4c;
    void *f50;
    void *f54;
    u8 f58;
} State;

extern State DAT_02734450;
u32 CheckState(void);
void ReplyCallback(u32 a0);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);

void CommonCallback(u32 a0, u32 a1, u32 a2) {
    u8 b2 = (a1 & 0xff0000) >> 16;
    u8 b1 = (a1 & 0xff00) >> 8;
    u8 b0 = a1 & 0xff;
    if (b2 == 0xfd) {
        if (CheckState() != 0) {
            return;
        }
        SetSndexWork(0, 0, 0, 0xfd);
    }
    if (a0 != 0x18 || a2 == 1
        || (DAT_02734450.state != 3 && DAT_02734450.state != 4 && DAT_02734450.state != 5)
        || DAT_02734450.f58 != b2) {
        ReplyCallback(7);
        return;
    }
    switch (b1) {
    case 0:
        switch (b2) {
        case 1:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        case 2:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        case 3:
        case 4:
            if (DAT_02734450.f54 != 0) {
                *(u8 *)DAT_02734450.f54 = b0;
            }
            break;
        case 5:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        case 0xfd:
            if (DAT_02734450.f2c != 0) {
                DAT_02734450.f2c(b1, DAT_02734450.f30);
            }
            break;
        case 0xfe:
            if (DAT_02734450.f54 != 0) {
                *(u32 *)DAT_02734450.f54 = b0;
            }
            break;
        }
        ReplyCallback(0);
        break;
    case 2:
        ReplyCallback(2);
        break;
    case 3:
        ReplyCallback(3);
        break;
    case 4:
        ReplyCallback(4);
        break;
    case 5:
        if (b2 == 4 && DAT_02734450.f54 != 0) {
            *(u8 *)DAT_02734450.f54 = 0;
        }
        ReplyCallback(6);
        break;
    default:
        ReplyCallback(7);
        break;
    }
}

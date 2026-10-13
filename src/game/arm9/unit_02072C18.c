/*
 * file:     unit_02072C18.c
 * unit:     yes
 * function: NNS_SndWaveOutSetVolume, NNS_SndWaveOutSetSpeed, NNS_SndWaveOutIsPlaying
 * address:  0x02072C18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02089618  0x02089618  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_02089D6C 0x02089D6C  arm
 *   func_0208A07C 0x0208A07C  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned long long u64;

typedef struct WaveOutSlot {
    u32 channelNo;              /* 0x00  channel index; mask is 1u << this   */
    int baseRate;               /* 0x04  first divisor                       */
    u32 active;                 /* 0x08  liveness guard                      */
    u32 started;                /* 0x0C  start command already acknowledged  */
    u32 commandTag;             /* 0x10  command tag to wait for             */
} WaveOutSlot;

extern void func_02089638(u32 chBitMask, int volume, int shift);
extern void func_02089618(u32 chBitMask, int timer);
extern int func_02089D6C(u32 tag);
extern u32 func_0208A07C(void);
void NNS_SndWaveOutSetSpeed(WaveOutSlot *slot, int speed);


void NNS_SndWaveOutSetVolume(WaveOutSlot *slot, u32 volume)
{
    if (slot->active == 0) return;
    func_02089638(1 << slot->channelNo, volume, 0);
}


/*
 * Writes the channel's timer period.  The period is the same chained 64-bit
 * division src/matched/unit_020067E0.c documents: the dividend is the
 * constant 0x7FD87F8000 (16756991 * 0x8000, half the DS system clock times
 * 0x8000), whose low word 0xD87F8000 sits in the pool at 0x02072CBC and whose
 * high word 0x7F fits a `mov r1, #0x7f`.  Both divisors are `int`s widened to
 * s64 by the `asr r3, rX, #0x1f` in front of each `bl 0x0209C00C`, which is
 * what makes two 32-bit divides impossible as a reading: the helper takes and
 * returns r0:r1, so the second call consumes the first call's quotient.
 *
 * THE ONE STRUCTURAL TELL, and the only byte difference the first attempt had:
 * the clamp is `if (t < 0x10) t = 0x10; else if (t > 0xFFFF) t = 0xFFFF;`, not
 * two independent `if`s.  Two independent `if`s give a fully if-converted
 * sequence (`movlo r3, r0 / movlo r1, r2 / cmp r1, #0 / ...`), and the image
 * instead branches out of the low clamp with `blo #0x2072ca4` over the whole
 * high clamp -- 24 concrete bytes, the entire residue.  The `else` is what
 * proves the two bounds are exclusive arms of one clamp in the original C.
 *
 * The upper bound 0xFFFF is the pool word at 0x02072CC0 and is compared as a
 * 64-bit value against r1:r3 with r2 = 0 as its high half, so the local is
 * `u64` all the way to the (u32) narrowing at the call.
 *
 * func_02089618 resolves sole-ref/code: 0x02089618 is a traced ARM function
 * start in asm/arm9/src/028_02087EA8.s and the `bl` here is the only branch to
 * it anywhere in the image.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndWaveOutSetSpeed.c \
 *       --func NNS_SndWaveOutSetSpeed --addr 0x02072C40 --arm --cc 1.1p1
 *   -> EXACT, compiled 132 = original 132, 3 of 3 sites resolved
 */
void NNS_SndWaveOutSetSpeed(WaveOutSlot *slot, int speed)
{
    u64 timer;

    if (slot->active == 0) {
        return;
    }
    timer = 0x7FD87F8000ULL / slot->baseRate / speed;
    if (timer < 0x10) {
        timer = 0x10;
    }
    else if (timer > 0xFFFF) {
        timer = 0xFFFF;
    }
    func_02089618(1 << slot->channelNo, (u32)timer);
}


int NNS_SndWaveOutIsPlaying(WaveOutSlot *slot)
{
    u32 channelStatus;

    if (slot->active == 0) return 0;
    if (slot->started == 0) {
        if (func_02089D6C(slot->commandTag) == 0) return 1;
        slot->started = 1;
    }
    channelStatus = func_0208A07C();
    if (channelStatus & (1u << slot->channelNo)) return 1;
    slot->active = 0;
    return 0;
}

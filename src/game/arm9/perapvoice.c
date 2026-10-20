/*
 * file:     perapvoice.c
 * unit:     yes
 * function: PERAPVOICE_GetSize, PERAPVOICE_Init, PERAPVOICE_Create, PERAPVOICE_GetFromSave, PERAPVOICE_IsRecorded, PERAPVOICE_ClearRecorded, PERAPVOICE_SetRecorded, PERAPVOICE_GetSamples, PERAPVOICE_Unpack, PERAPVOICE_Pack, PERAPVOICE_Copy, PERAPVOICE_ClearIfNoChatot, PERAPVOICE_GetVoiceKind
 * address:  0x02007B00
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from save_control.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   SAVE_CONTROL_GetBlock       0x020071CC  thumb
 *   _PerapVoiceFileName  0x020A707C  data
 *   MIi_CpuClear32      0x02082A7C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   PERAPVOICE_IsRecorded   0x02007B50  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 */
#include "btl_setup_types.h"
#include "box_savedata_shared_types.h"

#include "../types.h"

struct PokeParty;

struct Pokemon;

/* Chatot recording block, 0x3EC bytes. */
struct PerapVoice {
    u32 isRecorded;
    u8 samples[1000]; /* two signed 4 bit samples per byte */
};

#define PERAP_PACKED_BYTES 1000

#define PERAP_UNPACKED_BYTES (PERAP_PACKED_BYTES * 8)

#define PERAP_UNPACKED_SIZE 0x1FF4

#define SPECIES_CHATOT 0x1B9

#include "gfl_heap_wrap.h"

#include "mi_memory.h"

struct PokemonParam;

#include "poke_tool.h"
struct Party;

#include "pokeparty.h"


extern const char _PerapVoiceFileName[];

void PERAPVOICE_Init(struct PerapVoice *voice);

void PERAPVOICE_ClearRecorded(struct PerapVoice *voice);

u32 PERAPVOICE_IsRecorded(struct PerapVoice *voice);

#include "save_control.h"

/*
 * "perapvoice.c" starts here (Perap is the Japanese name of Chatot).
 * PERAPVOICE_Create passes 0x020A707C to the debug allocator with the line number
 * 0x57, and the bytes at 0x020A707C spell "perapvoice.c".  The string is
 * named by one pool word in the whole image and it is this function's own,
 * so the `literal` class discards its only witness; the `string` class
 * closes it, because "box_savedata.c" ends with its NUL at 0x020A707A and
 * one byte of padding puts the next string at 0x020A707C by construction.
 *
 * PERAPVOICE_GetSize returns the block size 0x3EC, which is what PERAPVOICE_Init
 * clears and what PERAPVOICE_Create allocates.  The object is one `u32` flag
 * followed by 1000 bytes, and PERAPVOICE_IsRecorded reads the flag that PERAPVOICE_ClearRecorded
 * and PERAPVOICE_SetRecorded write.  Four of the functions carry no label, because
 * none of them saves lr.
 */
u32 PERAPVOICE_GetSize(void)
{
    return sizeof(struct PerapVoice);
}

void PERAPVOICE_Init(struct PerapVoice *voice)
{
    MIi_CpuClear32(0, voice, sizeof(struct PerapVoice));
    voice->isRecorded = 0;
}

struct PerapVoice *PERAPVOICE_Create(u32 heapId)
{
    struct PerapVoice *voice = GFL_HEAP_Alloc(heapId, sizeof(struct PerapVoice), 1, _PerapVoiceFileName, 0x57);

    PERAPVOICE_Init(voice);
    return voice;
}

/* The recording block of the save. */
struct PerapVoice *PERAPVOICE_GetFromSave(struct SaveControl *saveControl)
{
    return SAVE_CONTROL_GetBlock(saveControl, 0x24);
}

u32 PERAPVOICE_IsRecorded(struct PerapVoice *voice)
{
    return voice->isRecorded;
}

/*
 * The payload is 1000 bytes holding two signed four bit samples each.
 * PERAPVOICE_Unpack expands them to 8000 bytes, four copies of each sample in the
 * high nibble of a byte, and zero fills to 0x1FF4; PERAPVOICE_Pack is the exact
 * inverse, 0x1F40 bytes in and 1000 out.  The bias of eight in both
 * directions is what makes the four bit field signed.
 *
 *  - the `lsls #28` / `asrs #24` pair at the end of each expansion is
 *    `(s8)(v << 4)` and not `v << 4`: the truncation is materialised because
 *    the value is assigned to an `s8` local before the inner store loop, and
 *    writing the shift straight into the store gives `lsls #4` alone.
 *  - PERAPVOICE_Pack packs the two nibbles into one byte with a plain store
 *    followed by an `|=`, which is why the byte is stored, reloaded with
 *    `ldrb` and stored again.  Neither half is masked on the way in, so the
 *    source is two `u8` statements and not a bitfield.
 *  - PERAPVOICE_Unpack reloads `src[i]` for the second nibble rather than keeping
 *    it: source and destination are both `s8 *`, so the stores in between may
 *    alias and the compiler has to re-read.
 */
void PERAPVOICE_ClearRecorded(struct PerapVoice *voice)
{
    voice->isRecorded = 0;
}

void PERAPVOICE_SetRecorded(struct PerapVoice *voice)
{
    voice->isRecorded = 1;
}

u8 *PERAPVOICE_GetSamples(struct PerapVoice *voice)
{
    return voice->samples;
}

/* Unpack the 4 bit samples to 8 bit PCM, each sample repeated four times. */
void PERAPVOICE_Unpack(s8 *dest, const s8 *src)
{
    int srcIndex;
    int repeat;
    int destIndex;

    destIndex = 0;
    for (srcIndex = 0; srcIndex < PERAP_PACKED_BYTES; srcIndex++) {
        s8 lowSample = (s8)((s8)((u8)(src[srcIndex] & 0xF) - 8) << 4);

        for (repeat = 0; repeat < 4; repeat++) {
            dest[destIndex + repeat] = lowSample;
        }
        {
            s8 highSample = (s8)((s8)((u8)(src[srcIndex] >> 4) - 8) << 4);

            for (repeat = 4; repeat < 8; repeat++) {
                dest[destIndex + repeat] = highSample;
            }
        }
        destIndex += 8;
    }
    for (srcIndex = PERAP_UNPACKED_BYTES; srcIndex < PERAP_UNPACKED_SIZE; srcIndex++) {
        dest[srcIndex] = 0;
    }
}

/* Pack 8 bit PCM into the 4 bit samples (inverse of the above) and mark the voice recorded. */
void PERAPVOICE_Pack(struct PerapVoice *voice, const s8 *src)
{
    int srcIndex;
    int destIndex;

    voice->isRecorded = 1;
    destIndex = 0;
    for (srcIndex = 0; srcIndex < PERAP_UNPACKED_BYTES; srcIndex += 8) {
        u8 lowNibble = (u8)((s8)(src[srcIndex] / 16) + 8);

        voice->samples[destIndex] = lowNibble;
        {
            u8 highNibble = (u8)((s8)(src[srcIndex + 4] / 16) + 8);

            voice->samples[destIndex] |= (u8)(highNibble << 4);
        }
        destIndex++;
    }
}

void PERAPVOICE_Copy(struct PerapVoice *dest, const struct PerapVoice *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PerapVoice));
}

/* Drop the recording when the party has no Chatot. */
void PERAPVOICE_ClearIfNoChatot(struct PerapVoice *voice, struct PokeParty *party)
{
    int index;
    int count = POKEPARTY_GetCount((struct Party *)party);

    for (index = 0; index < count; index++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((struct Party *)party, index), MON_DATA_SPECIES, 0) == SPECIES_CHATOT) {
            return;
        }
    }
    PERAPVOICE_ClearRecorded(voice);
}

/* Classify a recording by a check value of three payload bytes: 1 below 100, 2 from 150, else 0. */
u32 PERAPVOICE_GetVoiceKind(struct PerapVoice *voice)
{
    if (PERAPVOICE_IsRecorded(voice) == 1) {
        u8 checkValue = (u8)(voice->samples[0x64] ^ voice->samples[0x1F4] ^ voice->samples[0x2BC]);

        if (checkValue < 100) {
            return 1;
        }
        if (checkValue >= 150 && checkValue < 256) {
            return 2;
        }
    }
    return 0;
}

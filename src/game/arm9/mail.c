/*
 * file:     mail.c
 * unit:     yes
 * function: MAIL_Init, MAIL_IsDesignValid, MAIL_Create, MAIL_Copy, MAIL_InitForPlayer, MAIL_GetWriterId, MAIL_GetWriterName, MAIL_SetWriterName, MAIL_GetGender, MAIL_SetGender, MAIL_GetDesign, MAIL_SetDesign, MAIL_GetLanguage, MAIL_SetLanguage, MAIL_GetVersion, MAIL_SetVersion, MAIL_GetMessageId, MAIL_SetMessageId, MAIL_GetMessage, MAIL_SetMessage, MAIL_GetBox, MAIL_GetBoxSize, MAIL_InitBox, MAIL_FindEmptySlot, MAIL_ClearSlot, MAIL_SetSlot, MAIL_CreateSlotCopy, MAIL_FindEmptySlotInRange, MAIL_GetSlot
 * address:  0x02008EAC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mail.c by tools/splitfile.py.
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   MAIL_FileName      0x020A716C  data
 *   GAME_LANGUAGE_Code   0x0209DF0C  data
 *   GAME_VERSION_Code   0x0209DF08  data
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   PMSI_PARAM_ClearSentence  0x0202428C  thumb
 *   MIi_CpuClear16 0x02082A48  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 */
#include "trcard_sign_shared_types.h"

/* The mail box holds twenty letters. */
#define MAIL_BOX_CAPACITY 20

/* Mail designs are numbered 0..11; any other value marks an empty letter. */
#define MAIL_DESIGN_COUNT 12

#define SAVE_BLOCK_MAIL_BOX               0x28

struct GameData;

struct MyStatus;

/* ---- Mail ---- */

/* Easy-chat phrase (PMS data), eight bytes. */
struct PmsData {
    u16 sentenceType;
    u16 sentenceId;
    u16 word[2];
};

struct Mail {
    u32 writerId;
    u8  gender;
    u8  language;
    u8  version;
    u8  design;                     /* 0..11, 0xFF when empty */
    u16 writerName[8];
    u16 icon[3];
    u16 messageId;
    struct PmsData message[3];
};

struct MailBox {
    struct Mail mail[MAIL_BOX_CAPACITY];
};

extern void MIi_CpuClear16(u16 data, void *dest, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *control, u32 blockId);

extern u16  STRBUF_GetEosChar(void);

extern void PMSI_PARAM_ClearSentence(struct PmsData *pms);

extern void PMSI_PARAM_Copy(struct PmsData *dest, const struct PmsData *src);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                           u16 tag);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern const u16 *MYSTATUS_GetName(const struct MyStatus *status);

extern u32 MYSTATUS_GetId(const struct MyStatus *status);

extern u8  MYSTATUS_GetOutfitVariant(const struct MyStatus *status);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern const u8 GAME_LANGUAGE_Code;

extern const u8 GAME_VERSION_Code;

extern char MAIL_FileName[];

int MAIL_FindEmptySlotInRange(struct Mail *box, int count);

struct Mail *MAIL_GetSlot(struct Mail *box, u32 boxKind, int index);

/*
 * Mail.  The 0x38-byte letter is allocated with "mail.c" as the debug site
 * (MAIL_FileName, line 135).
 */
static inline void MI_CpuFill16(void *dest, u16 data, u32 size)
{
    MIi_CpuClear16(data, dest, size);
}

/* MI_CpuFill16 is the SDK header's inline wrapper: a direct blx MIi_CpuClear16
 * with the data and destination swapped.  The 0xFFFF at +0x1E is a pool word
 * (the Thumb immediate stops at 255); the 0xFF at +7 is a movs. */
void MAIL_Init(struct Mail *mail)
{
    int i;

    mail->writerId = 0;
    mail->gender = 0;
    mail->language = GAME_LANGUAGE_Code;
    mail->version = GAME_VERSION_Code;
    mail->design = 0xFF;
    MI_CpuFill16(mail->writerName, STRBUF_GetEosChar(), sizeof(mail->writerName));
    mail->messageId = 0xFFFF;
    for (i = 0; i < 3; i++) {
        PMSI_PARAM_ClearSentence(&mail->message[i]);
    }
}

/* Is the design one of the 12 valid ones.  bhi, not bgt, is the only
 * evidence of an unsigned compare. */
int MAIL_IsDesignValid(const struct Mail *mail)
{
    if (mail->design <= MAIL_DESIGN_COUNT - 1) {
        return 1;
    }
    return 0;
}

struct Mail *MAIL_Create(int heapId)
{
    struct Mail *mail = GFL_HEAP_Alloc((unsigned short)((heapId & 0x7fff) | 0x8000),
                                      sizeof(struct Mail), 0, MAIL_FileName, 0x87);

    MAIL_Init(mail);
    return mail;
}

/* Copy a whole letter.  Both pointers are already in the registers MI_CpuCopy8
 * wants; the bx r3 is a tail call to an ARM function through a pool word. */
void MAIL_Copy(const struct Mail *src, struct Mail *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Mail));
}

/* Fill a blank letter for the player.  The third parameter is dead.
 * MYSTATUS_GetName is an identity accessor on its argument, declared with the
 * type this call needs. */
void MAIL_InitForPlayer(struct Mail *mail, u8 design, u32 unused,
                  struct GameData *gameData)
{
    struct MyStatus *status;

    MAIL_Init(mail);
    mail->design = design;
    status = GAME_DATA_GetMyStatus(gameData);
    MI_CpuCopy8(MYSTATUS_GetName(status), mail->writerName, sizeof(mail->writerName));
    mail->gender = MYSTATUS_GetOutfitVariant(status);
    mail->writerId = MYSTATUS_GetId(status);
}

/*
 * Accessors of the letter.  MAIL_SetWriterName copies *into* the letter (the
 * argument shuffle builds the field address in r2, then puts the caller's
 * pointer in the source register).  MAIL_GetMessage tests index < 3 first and
 * falls out of range to entry 0; the other spelling inverts the branch and
 * swaps the arms.
 */
u32 MAIL_GetWriterId(const struct Mail *mail)
{
    return mail->writerId;
}

u16 *MAIL_GetWriterName(struct Mail *mail)
{
    return mail->writerName;
}

void MAIL_SetWriterName(struct Mail *mail, const void *name)
{
    MI_CpuCopy8(name, mail->writerName, sizeof(mail->writerName));
}

u8 MAIL_GetGender(const struct Mail *mail)
{
    return mail->gender;
}

void MAIL_SetGender(struct Mail *mail, u8 gender)
{
    mail->gender = gender;
}

u8 MAIL_GetDesign(const struct Mail *mail)
{
    return mail->design;
}

void MAIL_SetDesign(struct Mail *mail, u32 design)
{
    if (design < MAIL_DESIGN_COUNT) {
        mail->design = design;
    }
}

u8 MAIL_GetLanguage(const struct Mail *mail)
{
    return mail->language;
}

void MAIL_SetLanguage(struct Mail *mail, u8 language)
{
    mail->language = language;
}

u8 MAIL_GetVersion(const struct Mail *mail)
{
    return mail->version;
}

void MAIL_SetVersion(struct Mail *mail, u8 version)
{
    mail->version = version;
}

u16 MAIL_GetMessageId(const struct Mail *mail)
{
    return mail->messageId;
}

void MAIL_SetMessageId(struct Mail *mail, u16 messageId)
{
    mail->messageId = messageId;
}

struct PmsData *MAIL_GetMessage(struct Mail *mail, u32 index)
{
    if (index < 3) {
        return &mail->message[index];
    }
    return &mail->message[0];
}

void MAIL_SetMessage(struct Mail *mail, struct PmsData *pms, u32 index)
{
    if (index < 3) {
        PMSI_PARAM_Copy(&mail->message[index], pms);
    }
}

struct MailBox *MAIL_GetBox(struct GameData *gameData)
{
    return SAVE_CONTROL_GetBlock(GAME_DATA_GetSaveControl(gameData), SAVE_BLOCK_MAIL_BOX);
}

/*
 * The mail box: twenty letters, save block 0x28.  The size getter returns
 * 0x460, twenty times 0x38.  0x38 is not a power of two, so every index costs
 * a muls with the element size hoisted out of the loop.
 *
 * MAIL_SetSlot and MAIL_CreateSlotCopy are the only callers of MAIL_Copy in the
 * ROM, so matched in one range they attest each other's call site away; the
 * old split into separate files is the same trick as at CONSOLE_STAMP_SetIdentity.
 * MAIL_GetSlot ignores its second argument (a box kind): no instruction reads
 * r1, and the callers pass their own second argument straight through.
 */
u32 MAIL_GetBoxSize(void)
{
    return sizeof(struct MailBox);
}

void MAIL_InitBox(struct Mail *box)
{
    int i;

    for (i = 0; i < MAIL_BOX_CAPACITY; i++) {
        MAIL_Init(&box[i]);
    }
}

/* Index of the first empty letter in the box, or -1. */
int MAIL_FindEmptySlot(struct Mail *box)
{
    return MAIL_FindEmptySlotInRange(box, MAIL_BOX_CAPACITY);
}

/* Empty the letter at `index`. */
void MAIL_ClearSlot(struct Mail *box, u32 boxKind, int index)
{
    struct Mail *mail = MAIL_GetSlot(box, boxKind, index);

    if (mail != 0) {
        MAIL_Init(mail);
    }
}

/* Store a copy of `src` at `index`. */
void MAIL_SetSlot(struct Mail *box, u32 boxKind, int index,
                  const struct Mail *src)
{
    struct Mail *mail = MAIL_GetSlot(box, boxKind, index);

    if (mail != 0) {
        MAIL_Copy(src, mail);
    }
}

/* Return a new allocated copy of the letter at `index`. */
struct Mail *MAIL_CreateSlotCopy(struct Mail *box, u32 boxKind, int index, u32 heapId)
{
    struct Mail *mail = MAIL_GetSlot(box, boxKind, index);
    struct Mail *copy = MAIL_Create(heapId);

    if (mail != 0) {
        MAIL_Copy(mail, copy);
    }
    return copy;
}

/* The index of the first of `count` letters that is not valid, or -1. */
int MAIL_FindEmptySlotInRange(struct Mail *box, int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (MAIL_IsDesignValid(&box[i]) == 0) {
            return i;
        }
    }
    return -1;
}

/* The letter at `index`, or 0 when the index is outside the box. */
struct Mail *MAIL_GetSlot(struct Mail *box, u32 boxKind, int index)
{
    if (index < MAIL_BOX_CAPACITY) {
        return &box[index];
    }
    return 0;
}

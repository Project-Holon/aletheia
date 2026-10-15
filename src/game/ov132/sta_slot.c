/*
 * file:     sta_slot.c
 * unit:     yes
 * function: STA_SLOT_GetSub, STA_SLOT_SetValueByKey, STA_SLOT_GetStateByKey, STA_SLOT_ResetStateByKey, STA_SLOT_GetCurrentKey, STA_SLOT_ClearCurrent, STA_SLOT_PushRecord, STA_SLOT_GetRecordTable, STA_SLOT_Noop
 * address:  0x021FD964
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021FDDEC 0x021FDDEC data a4
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* One of four player slots of the staging state; stride 0x30. */
typedef struct StaSlot {
    int used;                /* +0x00 */
    unsigned char value;     /* +0x04 */
    unsigned char state;     /* +0x05, default 10 */
    unsigned char key;       /* +0x06 */
    unsigned char sub[0x29]; /* +0x07, per-subindex bytes */
} StaSlot;

/* Owner of the four slots and the outgoing record queue. */
typedef struct StaSlotOwner {
    unsigned char pad_0[0x6c];
    StaSlot slots[4];            /* +0x6c */
    unsigned char pad_12c[0x54];
    unsigned char currentSlot;   /* +0x180 */
    unsigned char pad_181[7];
    unsigned int queueFlag;      /* +0x188 */
    unsigned int queue[8];       /* +0x18c */
} StaSlotOwner;

u32 STA_SLOT_GetSub(char *p, u32 index, u32 subindex);
void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value);
unsigned char STA_SLOT_GetStateByKey(unsigned char *p, unsigned char key);
void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key);
int STA_SLOT_GetCurrentKey(char *p);
void STA_SLOT_ClearCurrent(unsigned char *p);
void STA_SLOT_PushRecord(StaSlotOwner *p, u32 a, u32 b, u32 c);
unsigned char *STA_SLOT_GetRecordTable(void *h);
void STA_SLOT_Noop(int a0, int a1, int a2);
extern unsigned char d_021FDDEC[];


u32 STA_SLOT_GetSub(char *p, u32 index, u32 subindex) { p = p + index * 0x30; return *(u8 *)(p + subindex + 0x73); }


/* A byte parameter keeps the store input live without an entry truncation. */
void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value) { u8 i; for (i = 0; i < 4; i++) { if (key == ((StaSlotOwner *)p)->slots[i].key) { ((StaSlotOwner *)p)->slots[i].used = 1; ((StaSlotOwner *)p)->slots[i].value = value; } } }


unsigned char STA_SLOT_GetStateByKey(unsigned char *p, unsigned char key) { unsigned char i; for (i = 0; i < 4; i++) { if (((StaSlotOwner *)p)->slots[i].key == key) return ((StaSlotOwner *)p)->slots[i].state; } return 10; }


void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key) { unsigned char i; for (i = 0; i < 4; i++) { if (((StaSlotOwner *)p)->slots[i].key == key) ((StaSlotOwner *)p)->slots[i].state = 10; } }



int STA_SLOT_GetCurrentKey(char *p)
{
    unsigned int i = ((StaSlotOwner *)p)->currentSlot;

    if (i < 4)
        return ((StaSlotOwner *)p)->slots[i].key;
    return 4;
}


void STA_SLOT_ClearCurrent(unsigned char *p) { ((StaSlotOwner *)p)->currentSlot = 4; }


void STA_SLOT_PushRecord(StaSlotOwner *p, u32 a, u32 b, u32 c)
{
    u8 i;
    for (i = 0; i < 8; i++) {
        if (p->queue[i] == 0xffff) {
            p->queue[i] = (c << 16) + (a << 8) + b;
            p->queueFlag = 1;
            return;
        }
    }
}


unsigned char *STA_SLOT_GetRecordTable(void *h) { return d_021FDDEC; }

void STA_SLOT_Noop(int a0, int a1, int a2)
{
}

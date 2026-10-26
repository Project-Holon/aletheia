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

#include "../types.h"

#include "ov132_types.h"

u32 STA_SLOT_GetSub(char *p, u32 index, u32 subindex);
void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value);
unsigned char STA_SLOT_GetStateByKey(unsigned char *p, unsigned char key);
void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key);
int STA_SLOT_GetCurrentKey(char *p);
void STA_SLOT_ClearCurrent(unsigned char *p);
void STA_SLOT_PushRecord(struct ActingHost *p, u32 a, u32 b, u32 c);
unsigned char *STA_SLOT_GetRecordTable(void *h);
void STA_SLOT_Noop(void *buffer, int size, int kind);
extern unsigned char d_021FDDEC[];

u32 STA_SLOT_GetSub(char *p, u32 index, u32 subindex) { p = p + index * (int)sizeof(struct StaActRecord); return ((struct ActingHost *)p)->rec[0].items[subindex]; }

/* A byte parameter keeps the store input live without an entry truncation. */
void STA_SLOT_SetValueByKey(char *p, u32 key, u8 value) { u8 i; for (i = 0; i < 4; i++) { if (key == ((struct ActingHost *)p)->rec[i].key) { ((struct ActingHost *)p)->rec[i].used = 1; ((struct ActingHost *)p)->rec[i].value = value; } } }

unsigned char STA_SLOT_GetStateByKey(unsigned char *p, unsigned char key) { unsigned char i; for (i = 0; i < 4; i++) { if (((struct ActingHost *)p)->rec[i].key == key) return ((struct ActingHost *)p)->rec[i].state; } return 10; }

void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key) { unsigned char i; for (i = 0; i < 4; i++) { if (((struct ActingHost *)p)->rec[i].key == key) ((struct ActingHost *)p)->rec[i].state = 10; } }

int STA_SLOT_GetCurrentKey(char *p)
{
    unsigned int i = ((struct ActingHost *)p)->chosenPlayer;

    if (i < 4)
        return ((struct ActingHost *)p)->rec[i].key;
    return 4;
}

void STA_SLOT_ClearCurrent(unsigned char *p) { ((struct ActingHost *)p)->chosenPlayer = 4; }

void STA_SLOT_PushRecord(struct ActingHost *p, u32 player, u32 action, u32 result)
{
    u8 i;
    for (i = 0; i < 8; i++) {
        if (p->pickCommand[i] == 0xffff) {
            p->pickCommand[i] = (result << 16) + (player << 8) + action;
            p->pickSendPending = 1;
            return;
        }
    }
}

unsigned char *STA_SLOT_GetRecordTable(void *unused) { return d_021FDDEC; }

void STA_SLOT_Noop(void *buffer, int size, int kind)
{
}

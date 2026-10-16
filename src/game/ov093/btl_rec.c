/*
 * file:     btl_rec.c
 * unit:     yes
 * function: BTL_REC_CreateBuffer, BTL_REC_DeleteBuffer, BTL_REC_AppendPacket, BTL_REC_GetPacketId, BTL_REC_ReadEntry, BTL_REC_InitReader, BTL_REC_ResetReader, BTL_REC_ReadSkipFlag, BTL_REC_ReadRecord, BTL_REC_CountFlaggedRecords, BTL_REC_IsChannelDone, BTL_REC_InitPacket, BTL_REC_MakeSkipPacket, BTL_REC_AddRecord, BTL_REC_FinishPacket, BTL_REC_MakeResetPacket, BTL_REC_LoadPacket, BTL_REC_NextRecord
 * address:  0x021EE5E4
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
 *   HAND_FIELD_AddFactor  0x06898020  thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   BTL_SIDE_GetSlotOfClientThunk 0x021B9AF8 thumb ov093
 *   BTL_SLOT_GetCount 0x021B9B94 thumb ov093
 *   BTL_SLOT_GetPokeParam 0x021B9C00 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTLV_SCU_StartMessage  0x021ECEB8  thumb  ov093
 *   BTLV_SCU_UpdateMessage   0x021ECF68  thumb  ov093
 *   FADE_Start  0x0204E720  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BTLV_SCU_IsFadeDone  0x021EB318  thumb  ov093
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BTL_POKEPARAM_ReadStatsFromMon  0x021D590C  thumb  ov093
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   BMP_WIN_GetHeight  0x02045740  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gBtlRecFileName  0x021F3ADC  data  a4
 *   GFL_HEAP_Free   0x020307B0  arm arm9
 *   MI_CpuCopy8  0x02082D44  arm
 *   BTL_CALC_ActionSetRecordError  0x021D8470  thumb
 *   BTL_CALC_ActionSetRecordReset  0x021D845C  thumb
 *   gBtlAdapterSlots  0x021F6388  data  a4
 *   gBtlAdapterMode  0x021F6384  data  a4
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   gBtlAdapterFileName     0x021F3AE8  data  ov093  a4
 *   BTL_NET_ExpectReplies   0x021D4C58  thumb
 *   BTL_NET_SendServerCmd  0x021D4B58  thumb  ov093
 *   BTL_NET_AreAllRepliesReceived  0x021D4B98  thumb  ov093
 *   BTL_NET_GetClientReply  0x021D4BD4  thumb  ov093
 *   BTL_NET_HasServerCmd  0x021D4C60  thumb  ov093
 *   BTL_NET_GetServerCmd  0x021D4C6C  thumb  ov093
 *   BTL_NET_SendClientReply  0x021D4C84  thumb  ov093
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   gBtlMsgState     0x021F6398  data  ov093  a4
 *   gBtlMsgFlags     0x021F63D8  data  ov093  a4
 *   sBtlMsgBankFileIds     0x021F3990  data  ov093  a2
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   WORDSET_SetSlotMonSpecies  0x0201EEF4  thumb
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   WORDSET_SetSlotMonName  0x0201EE84  thumb
 *   BTL_MAIN_GetTrainerType  0x021BA020  thumb  ov093
 *   WORDSET_Set  0x0201F0F8  thumb
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_MAIN_GetTrainerId  0x021BA004  thumb  ov093
 *   BTL_MAIN_GetTrainerNameAndType  0x021B9FAC  thumb  ov093
 *   BTL_MAIN_GetTrainerHandle  0x021BA064  thumb  ov093
 *   BTL_MAIN_UpdateCommPlayerSupport  0x021BA080  thumb  ov093
 *   TPOKE_DATA_GetGenderValue  0x0202A3CC  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb
 *   d_021F63C8     0x021F63C8  data  a4
 *   BTL_MAIN_IsLocalSide  0x021B8BD0  thumb  ov093
 *   sBtlMsgSidePairIds     0x021F39A0  data  a2
 *   func_02045CAC  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   sBtlMsgBuilders  0x021F39D8  data  a4
 *   d_021F39DC  0x021F39DC  data  a4
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   GF_FONT_GetTagChar  0x0201D5C4  thumb
 *   GF_FONT_CheckD5CC  0x0201D5CC  thumb
 *   GF_FONT_GetTagParam  0x0201D670  thumb
 *   GF_FONT_GetTagGroup  0x0201D5F4  thumb
 *   GF_FONT_GetTagKind  0x0201D658  thumb
 *   GF_FONT_SkipTag  0x0201D688  thumb
 *   STRBUF_GetChars  0x02045A90  arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   WORDSET_SetSlotFromMsgC7 0x0201F020 thumb
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsOpposingPos  0x021B8CE8  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTLV_CORE_GetZeroMasked  0x021E8918  thumb  ov093
 *   gBtlFieldCountdown  0x021F63F4  data  a4
 *   BTL_FIELD_RemoveSlot  0x021EFA94  thumb  ov093
 *   BTL_FIELD_AddSlotHolder  0x021EFAD8  thumb  ov093
 *   BTL_FIELD_RemoveHolderFromSlots  0x021EFB34  thumb  ov093
 *   BTL_FIELD_IsMoveSealedBySlot  0x021EFC1C  thumb  ov093
 *   BTL_FIELD_TickSlots  0x021EFC78  thumb  ov093
 *   BTL_FIELD_IsSlotInUse  0x021EFCE4  thumb  ov093
 *   gBtlFieldFileName  0x021F3AF8  data  a4
 *   BTLV_CORE_GetSlotPosition  0x021E8A98  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Replay buffer of one battle: records are appended after the 8 byte head
 * until 0xC00 bytes are used, then the overflow flag is set. */
typedef struct {
    u16 writeOffset;
    u8 overflowed;
    u8 reserved[5];
    u8 data[0xC00];
} BtlRecBuffer;

/* Read side of a recording: four channels (one per client) walk the same
 * byte stream; each channel keeps its own position and its last record. */
typedef struct {
    u8 *bytes;
    u32 size : 31;
    u32 failed : 1;
    u32 readPos[4];
    u32 lastRecord[4][16];
} BtlRecReader;

/* Write side: one packet of at most 60 bytes. data[0] is the packet id,
 * data[1] the header byte (bits 0-3 count, 4-6 type, 7 flag), then the
 * sub-records (channel in bits 5-7 and size in words in bits 0-4, followed
 * by the words). */
typedef struct {
    u8 used;
    u8 channelMask;
    u8 recordCount;
    u8 type : 6;
    u8 flag : 1;
    u8 full : 1;
    u8 data[60];
} BtlRecPacket;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
void BTL_CALC_ActionSetRecordError(u32 *record);
void BTL_CALC_ActionSetRecordReset(u32 *record);
extern char gBtlRecFileName[];

void *BTL_REC_CreateBuffer(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 0xC08, 1, gBtlRecFileName, 0x6b);
}


/*
 * tail-call thunk to GFL_HEAP_Free
 */
void BTL_REC_DeleteBuffer(void *buffer)
{
    GFL_HEAP_Free(buffer);
}


void BTL_REC_AppendPacket(BtlRecBuffer *buffer, const u8 *src, int size)
{
    u32 offset;
    u32 end;

    if (buffer->overflowed == 0) {
        offset = buffer->writeOffset;
        size = size - 1;
        end = offset + size;
        if (end <= 0xC00) {
            MI_CpuCopy8(src + 1, &buffer->data[offset], size);
            buffer->writeOffset = end;
        } else {
            buffer->overflowed = 1;
        }
    }
}


/*
 * Reads the u8 field at offset 0 of the argument and returns it.
 */
u8 BTL_REC_GetPacketId(u8 *src) { return *src; }


unsigned short *BTL_REC_ReadEntry(unsigned short *entry, unsigned int *outValue)
{
    *outValue = *entry;
    return entry + 4;
}


void BTL_REC_InitReader(BtlRecReader *reader, u32 bytesAddr, u32 size)
{
    u32 channel;

    reader->bytes = (u8 *)bytesAddr;
    reader->size = size;
    reader->failed = 0;
    for (channel = 0; channel < 4; channel++)
        reader->readPos[channel] = 0;
}


void BTL_REC_ResetReader(BtlRecReader *reader)
{
    u32 channel;

    for (channel = 0; channel < 4; channel++)
        reader->readPos[channel] = 0;
}


/*
 * Stream-record head decoder. Reads the byte at the position of channel
 * i; if its type field ((v >> 4) & 7) is 2, advances the channel
 * and returns bit 7. The int return type and the reuse of v for the bit
 * fix the order: type cannot be forwarded past the redefinition of v, and
 * the u8 cast lands at the assignment, not at the return.
 */
int BTL_REC_ReadSkipFlag(BtlRecReader *reader, int channel)
{
    int v;
    int type;

    v = reader->bytes[reader->readPos[channel]];
    type = (v >> 4) & 7;
    v = (u8)((v >> 7) & 1);
    if (type == 2) {
        reader->readPos[channel]++;
        return v;
    }
    return 0;
}


/*
 * Reads the next record for a channel from a packed byte stream. Header byte:
 * bits 0-3 count, bits 4-6 type, bit 7 flag. Type 1 carries count sub-records
 * (bits 0-4 size in words, bits 5-7 channel); the one for the channel is copied
 * into lastRecord[channel]. Type 2 is a skip, type 3 resets lastRecord[channel].
 * Any error sets failed. The final bounds check reads size and the position
 * into separate locals: that keeps the size shift pair ahead of the position
 * load.
 */
u32 *BTL_REC_ReadRecord(BtlRecReader *reader, u32 channel, u8 *outSize, u8 *outFlag)
{
    u32 *readPos;
    u32 start;
    if (reader->failed) {
        BTL_CALC_ActionSetRecordError(reader->lastRecord[channel]);
        *outSize = 1;
        *outFlag = 0;
        return reader->lastRecord[channel];
    }
    readPos = reader->readPos;
    while ((start = readPos[channel]) < reader->size) {
        u8 header = reader->bytes[start];
        u8 count = header & 0xF;
        int type = (header >> 4) & 7;
        *outFlag = (header >> 7) & 1;
        readPos[channel]++;
        if (readPos[channel] > reader->size)
            break;
        if (type == 1) {
            u32 *found = 0;
            u32 i;
            if (count == 0 || count > 4)
                break;
            for (i = 0; i < count; i++) {
                u32 at = readPos[channel]++;
                u8 *bytes = reader->bytes;
                u8 sub = bytes[at];
                u8 subChannel = (sub >> 5) & 7;
                u8 words = sub & 0x1F;
                if (readPos[channel] >= reader->size)
                    break;
                if (subChannel != channel) {
                    readPos[channel] += words * 4;
                } else {
                    MI_CpuCopy8(bytes + readPos[channel], reader->lastRecord[channel], words * 4);
                    found = reader->lastRecord[channel];
                    readPos[channel] += words * 4;
                    *outSize = words;
                }
            }
            if (found)
                return found;
        } else if (type == 3) {
            u32 *record = reader->lastRecord[channel];
            BTL_CALC_ActionSetRecordReset(record);
            *outSize = 1;
            *outFlag = 0;
            return record;
        } else if (type != 2) {
            break;
        }
        {
            u32 size = reader->size;
            u32 pos = readPos[channel];
            if (pos >= size)
                break;
        }
    }
    reader->failed = 1;
    BTL_CALC_ActionSetRecordError(reader->lastRecord[channel]);
    *outSize = 1;
    *outFlag = 0;
    return reader->lastRecord[channel];
}


/*
 * Counts the bit7-flagged records in a stream.
 * The buffer is read through reader->bytes in the loop (the compiler hoists
 * it), the bound is a local, and the locals are declared count first and
 * pos/size last; these set the register colours. pos++ sits right after
 * the byte load.
 */
int BTL_REC_CountFlaggedRecords(BtlRecReader *reader)
{
    int count;
    u8 header;
    u8 subCount;
    int type;
    u8 flag;
    u32 j;
    u8 words;
    u32 pos;
    u32 size;

    pos = 0;
    count = 0;
    size = reader->size;
    if (size != 0) {
        do {
            header = reader->bytes[pos];
            pos++;
            subCount = header & 0xf;
            type = (header >> 4) & 7;
            flag = (header >> 7) & 1;
            if (flag != 0)
                count++;
            if (pos >= size)
                break;
            if (type != 1) {
                pos += subCount;
            } else {
                for (j = 0; j < subCount; j++) {
                    words = reader->bytes[pos] & 0x1f;
                    pos = pos + 1 + words * 4;
                    if (pos >= size)
                        break;
                }
            }
        } while (pos < size);
    }
    return count;
}


int BTL_REC_IsChannelDone(BtlRecReader *reader, int channel)
{
    u32 pos;

    if (reader->failed == 0) {
        pos = reader->readPos[channel];
        if (pos == reader->size)
            return 1;
        return 0;
    }
    return 1;
}


void BTL_REC_InitPacket(BtlRecPacket *packet, int flag)
{
    MI_CpuFill8(packet, 0, 0x40);
    packet->flag = (u8)flag;
}


u8 *BTL_REC_MakeSkipPacket(BtlRecPacket *packet, u32 *outSize, int flag)
{
    packet->data[0] = 4;
    packet->data[1] = 0x20 | (((u8)flag & 1) << 7);
    *outSize = 2;
    return packet->data;
}


void BTL_REC_AddRecord(BtlRecPacket *packet, u8 channel, const void *words, u32 count)
{
    u8 mask;
    int size;
    u32 end;

    if (packet->used == 0) {
        packet->type = 1;
        packet->used = 2;
    }
    mask = packet->channelMask;
    if (!(mask & (1 << channel))) {
        size = count * 4;
        end = packet->used + (size + 1);
        if (end <= 0x3c) {
            packet->channelMask = mask | (u8)(1 << channel);
            packet->recordCount++;
            packet->data[packet->used] = (channel << 5) | count;
            MI_CpuCopy8(words, &packet->data[packet->used + 1], size);
            packet->used = end;
        } else {
            packet->full = 1;
        }
    }
}


u8 *BTL_REC_FinishPacket(BtlRecPacket *packet, u8 id, u32 *outSize)
{
    u8 type;

    if (packet->full == 0) {
        packet->data[0] = id;
        type = packet->type;
        packet->data[1] = 0;
        packet->data[1] = ((packet->flag & 1) << 7) | ((type & 7) << 4) | (packet->recordCount & 0xf);
        *outSize = packet->used;
        return packet->data;
    }
    return 0;
}


u8 *BTL_REC_MakeResetPacket(BtlRecPacket *packet, u32 *outSize)
{
    packet->data[0] = 0;
    packet->data[1] = 0x30;
    *outSize = 2;
    return packet->data;
}


void BTL_REC_LoadPacket(BtlRecPacket *packet, const void *src, int size)
{
    MI_CpuCopy8(src, packet->data, size);
    packet->used = size;
    packet->channelMask = 0;
    packet->recordCount = 0;
    packet->type = 0;
    packet->flag = 0;
    packet->full = 0;
}


int BTL_REC_NextRecord(BtlRecPacket *packet, u32 *pos, u8 *outChannel, u8 *outWords, u32 *dst)
{
    u8 header;
    int size;

    if (*pos == 0) {
        *pos = 2;
    }
    if (*pos < packet->used) {
        header = packet->data[*pos];
        *outChannel = (header >> 5) & 7;
        *outWords = header & 0x1f;
        size = *outWords * 4;
        *pos = *pos + 1;
        MI_CpuCopy8(&packet->data[*pos], dst, size);
        *pos = *pos + size;
        return 1;
    }
    return 0;
}

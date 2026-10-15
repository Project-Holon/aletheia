/*
 * file:     config.c
 * unit:     yes
 * function: CONFIG_InitKeyControlTable, CONFIG_Create, CONFIG_Copy, CONFIG_Init, CONFIG_GetTextSpeed, CONFIG_SetTextSpeed, CONFIG_GetSoundMode, CONFIG_SetSoundMode, CONFIG_GetBattleScene, CONFIG_SetBattleScene, CONFIG_GetBattleStyle, CONFIG_SetBattleStyle, CONFIG_GetAppliedFlag, CONFIG_SetAppliedFlag, CONFIG_ApplyAppliedFlag, CONFIG_GetButtonMode, CONFIG_SetButtonMode, CONFIG_GetBattleFlag, CONFIG_SetBattleFlag, MYSTATUS_GetSize, MYSTATUS_Create, MYSTATUS_Copy, MYSTATUS_Init, MYSTATUS_IsNameEmpty, MYSTATUS_CopyName, MYSTATUS_NameFromStrbuf, MYSTATUS_GetName, MYSTATUS_CopyNameChars, MYSTATUS_NameToStrbuf, MYSTATUS_CreateNameStrbuf, MYSTATUS_SetId, MYSTATUS_GetId, MYSTATUS_GetIdLow16, MYSTATUS_GetProfileId, MYSTATUS_SetProfileIdOnce, MYSTATUS_SetOutfitVariant, MYSTATUS_GetOutfitVariant, MYSTATUS_GetOutfit, MYSTATUS_SetOutfit, MYSTATUS_GetAvatarId, MYSTATUS_SetAvatarId, MYSTATUS_GetGender, MYSTATUS_SetGender, MYSTATUS_GetLanguage, MYSTATUS_GetVersion, MYSTATUS_SetLanguageAndVersion, PLAYTIME_Create, PLAYTIME_Init, PLAYTIME_AddSeconds, PLAYTIME_Copy, PLAYTIME_GetHours, PLAYTIME_GetMinutes, PLAYTIME_GetSeconds, PLAYTIME_SetStampNow, PLAYTIME_GetStampYear, PLAYTIME_GetStampMonth, PLAYTIME_GetStampDay, PLAYTIME_GetStampHour, PLAYTIME_GetStampMinute, PLAYTIME_GetStamp, PLAYTIME_SetStamp, SYSTEM_DATA_GetSize, SYSTEM_DATA_Init, SYSTEM_DATA_GetMyStatus, SYSTEM_DATA_GetConfig, SYSTEM_DATA_GetPlayTime, SYSTEM_DATA_IsActive, SYSTEM_DATA_SetActive, SYSTEM_DATA_ClearActive, SYSTEM_DATA_IsMarked, SYSTEM_DATA_SetMark, SYSTEM_DATA_ClearMark, SYSTEM_DATA_GetWordSlot, SYSTEM_DATA_SetMyStatus, SYSTEM_DATA_CopyMyStatus, PLAYER_LOCATION_GetSize, PLAYER_LOCATION_Init, PLAYER_LOCATION_Nop, PLAYER_LOCATION_GetLocationA, PLAYER_LOCATION_GetLocationB, PLAYER_LOCATION_GetShortData, PLAYER_LOCATION_GetData, PLAYER_LOCATION_SetRecordFromBuffer, PLAYER_LOCATION_CopyRecordToBuffer, PLAYER_LOCATION_CopyRecord, PLAYER_LOCATION_ReadStyleFrom, PLAYER_LOCATION_WriteStyleTo, PLAYER_LOCATION_SetFlagA, PLAYER_LOCATION_GetFlagA, PLAYER_LOCATION_SetFlagB, PLAYER_LOCATION_GetFlagB, PLAYER_LOCATION_SetCounter, PLAYER_LOCATION_GetCounter, PLAYER_LOCATION_GetValueA, PLAYER_LOCATION_SetValueA, PLAYER_LOCATION_SetValueB, PLAYER_LOCATION_GetValueB, PLAYER_LOCATION_GetZoneId, PLAYER_LOCATION_SetZoneId
 * address:  0x020082DC
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
 *   g_save_block_table      0x0209DD64  data
 *   config_file_name      0x020A70A0  data
 *   func_020461D4  0x020461D4  arm
 *   mystatus_file_name      0x020A70AC  data
 *   sub_0201F41C        0x0201F41C  thumb
 *   STRBUF_SetString        0x02045924  arm
 *   STRBUF_ToChars        0x02045A38  arm
 *   STRBUF_Create        0x020457B0  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   RTC_GetDate         0x02088864  arm
 *   RTC_GetTime         0x0208890C  arm
 *   playtime_file_name   0x020A70B8  data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   PLAYTIME_Init    0x020085A0  thumb
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *   MI_CpuFill8   0x02082BCC  arm
 *   KEY_SetControlModeTable  0x020362A4  arm
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   FIELD_STATUS_IsFlashActive  0x02014468  thumb
 */
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef signed short       s16;
typedef unsigned int       u32;

struct Strbuf;

/* Player options: one u16 of packed settings plus two reserved bytes. */
struct Config {
    u16 text_speed   : 4;
    u16 sound_mode   : 2;
    u16 battle_style      : 1;
    u16 battle_scene      : 1;
    u16 applied_flag      : 1;
    u16 button_mode      : 1;
    u16 battle_flag     : 1;
    u16 window_frame : 5;
    u16 reserved;
};

/* The 0x20-byte player record.  The name is eight u16 characters; the other
 * fields are only read and written as scalars. */
struct MyStatus {
    u16 name[8];
    u32 id;
    u32 profile_id;
    u8  language;
    u8  version;
    u8  gender;
    u8  avatar_id;
    u8  outfit;
    u8  outfit_variant;
};

struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
};

/* The packed date and time is a nested struct, not bitfields in PlayTime:
 * PLAYTIME_GetStamp and PLAYTIME_SetStamp move it as one ldr/str pair. */
struct PlayTimeStamp {
    u32 year   : 7;
    u32 month  : 4;
    u32 day    : 5;
    u32 hour   : 5;
    u32 minute : 6;
};

struct PlayTime {
    u16 hours;
    u8  minutes;
    u8  seconds;
    struct PlayTimeStamp stamp;
};

/* Save block 0x1B, 0x68 bytes. */
struct SystemData {
    struct Config config;
    struct MyStatus mystatus;
    struct PlayTime playtime;
    u8  active;
    u8  reserved2D[3];
    u16 marks[10];      /* each 0 or 0xC21E */
    u32 words[9];
};

/* The carrier a MyStatus is copied to and from, 0x20 bytes into a larger record. */
struct MyStatusHolder {
    u8 head[0x20];
    struct MyStatus mystatus;
};

/* A three-word position, moved as one ldm/stm unit. */
struct Position {
    u32 x;
    u32 y;
    u32 z;
};

/* The 0x1C-byte record the block keeps at +0x80. */
struct LocationRecord {
    u16 zone_id;
    struct Position position;
    u16 facing;
    u16 entrance_id;
    u16 form;
    u16 look;
    s16 height_offset;
    u8  kind;
    u8  flags;
};

/* The buffer the record is exchanged with.  Its first 0x1C bytes line up with
 * the record, but height_offset is unsigned and the record's last two bytes come from
 * flags and flags_word. */
struct LocationRecordBuf {
    u16 zone_id;
    struct Position position;
    u16 facing;
    u16 entrance_id;
    u16 form;
    u16 look;
    u16 height_offset;
    u8  kind;
    u8  flags;
    u8  reserved1C[0x24];
    u32 flags_word;
};

/* Save block 0x1C, 0x9C bytes. */
struct PlayerLocationData {
    u8  reserved00[0x38];
    u8  location_a[0x1C];
    u8  location_b[0x1C];
    u8  short_data[2];
    u8  style;
    u8  flag_a;
    u8  flag_b;
    u8  reserved75;
    u16 zone_id;
    u32 counter;
    u16 value_a;
    u16 value_b;
    struct LocationRecord record;
};

#define BLOCK_ID_1B 0x1B
#define BLOCK_ID_1C 0x1C

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void RTC_GetDate(struct RTCDate *date);
extern void RTC_GetTime(struct RTCTime *time);

/* The debug allocator: heap, size, clear, __FILE__ string, __LINE__. */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void KEY_SetControlModeTable(const void *arg);
extern u8 func_020461D4(u32 flag);
extern void sub_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void STRBUF_SetString(struct Strbuf *strbuf, const u16 *src);
extern void STRBUF_ToChars(struct Strbuf *strbuf, u16 *out, u32 n);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void FIELD_STATUS_SetFlashActive(void *dest, u8 value);
extern u8 FIELD_STATUS_IsFlashActive(const void *src);
/* Save-block lookup: returns the block with the given id. */
extern void *SAVE_CONTROL_GetBlock(void *save, u32 id);

extern char g_save_block_table[];
extern char config_file_name[];
extern char mystatus_file_name[];
extern const char playtime_file_name[];

void CONFIG_Init(struct Config *config);
void MYSTATUS_Init(struct MyStatus *mystatus);
void MYSTATUS_SetAvatarId(struct MyStatus *mystatus, u8 avatar_id);
void MYSTATUS_NameToStrbuf(const u16 *name, struct Strbuf *buf);
void PLAYTIME_Init(struct PlayTime *playtime);
struct PlayerLocationData *PLAYER_LOCATION_GetData(void *save);


void CONFIG_InitKeyControlTable(void)
{
    KEY_SetControlModeTable(g_save_block_table);
}


void *CONFIG_Create(int heap_id)
{
    struct Config *config = func_02030734((u16)heap_id, sizeof(struct Config), 0, config_file_name, 0x4d);
    CONFIG_Init(config);
    return config;
}


void CONFIG_Copy(const struct Config *src, struct Config *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Config));
}


void CONFIG_Init(struct Config *config)
{
    MI_CpuFill8(config, 0, sizeof(struct Config));
    config->text_speed = 1;
    config->sound_mode = 0;
    config->battle_style    = 0;
    config->battle_scene    = 0;
    config->applied_flag    = 0;
    config->button_mode    = 1;
    config->battle_flag   = 0;
}


unsigned int CONFIG_GetTextSpeed(const struct Config *config)
{
    return config->text_speed;
}


void CONFIG_SetTextSpeed(struct Config *config, unsigned int value)
{
    config->text_speed = (u16)value;
}


unsigned int CONFIG_GetSoundMode(const struct Config *config)
{
    return config->sound_mode;
}


void CONFIG_SetSoundMode(struct Config *config, unsigned int value)
{
    config->sound_mode = (u16)value;
}


unsigned int CONFIG_GetBattleScene(const struct Config *config)
{
    return config->battle_scene;
}


void CONFIG_SetBattleScene(struct Config *config, unsigned int value)
{
    config->battle_scene = (u16)value;
}


unsigned int CONFIG_GetBattleStyle(const struct Config *config)
{
    return config->battle_style;
}


void CONFIG_SetBattleStyle(struct Config *config, unsigned int value)
{
    config->battle_style = (u16)value;
}


int CONFIG_GetAppliedFlag(const struct Config *config)
{
    return config->applied_flag;
}


/* Sets applied_flag from the low bit of value, then passes the stored flag to
 * func_020461D4. */
void CONFIG_SetAppliedFlag(struct Config *config, unsigned int value)
{
    config->applied_flag = (u16)value;

    func_020461D4((u8)config->applied_flag);
}


/* Calls func_020461D4 with applied_flag as it stands. */
u8 CONFIG_ApplyAppliedFlag(const struct Config *config)
{
    return func_020461D4((u8)config->applied_flag);
}


int CONFIG_GetButtonMode(const struct Config *config)
{
    return config->button_mode;
}


void CONFIG_SetButtonMode(struct Config *config, unsigned int value)
{
    config->button_mode = (u16)value;
}


unsigned int CONFIG_GetBattleFlag(const struct Config *config)
{
    return config->battle_flag;
}


void CONFIG_SetBattleFlag(struct Config *config, int enabled)
{
    config->battle_flag = (u16)enabled;
}

int MYSTATUS_GetSize(void)
{
    return sizeof(struct MyStatus);
}

void *MYSTATUS_Create(int heap_id)
{
    struct MyStatus *mystatus = func_02030734((u16)heap_id, sizeof(struct MyStatus), 0, mystatus_file_name, 0x34);
    MYSTATUS_Init(mystatus);
    return mystatus;
}


void MYSTATUS_Copy(const struct MyStatus *src, struct MyStatus *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct MyStatus));
}


void MYSTATUS_Init(struct MyStatus *mystatus)
{
    MI_CpuFill8(mystatus, 0, sizeof(struct MyStatus));
    mystatus->gender = 2;
    MYSTATUS_SetAvatarId(mystatus, 0x15);
}

/* Non-zero when all eight name characters are zero. */
int MYSTATUS_IsNameEmpty(const struct MyStatus *mystatus)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (mystatus->name[i] != 0) {
            return 0;
        }
    }
    return 1;
}


/* The argument swap below is what -interworking produces for language tail call
 * to an extern whose instruction set the compiler cannot see: 0x0201F41C is
 * Thumb (odd pool word), 0x02045A38 is ARM (even), and the same code covers
 * both. */
void MYSTATUS_CopyName(u16 *dest, const u16 *src)
{
    sub_0201F41C(src, dest, 8);
}


void MYSTATUS_NameFromStrbuf(u16 *out, struct Strbuf *buf)
{
    STRBUF_ToChars(buf, out, 8);
}

const void *MYSTATUS_GetName(const void *mystatus)
{
    return mystatus;
}


void MYSTATUS_CopyNameChars(const u16 *src, u16 *dest, u32 n)
{
    sub_0201F41C(src, dest, n);
}


/* Also an argument-swapping tail call, 16 bytes instead of 12: the extra
 * `adds` is the third scratch register the swap needs when only two
 * arguments are live. */
void MYSTATUS_NameToStrbuf(const u16 *name, struct Strbuf *buf)
{
    STRBUF_SetString(buf, name);
}

/* heap_id is passed as int and narrowed here: a u16 parameter would be
 * truncated by the caller. */
struct Strbuf *MYSTATUS_CreateNameStrbuf(const u16 *name, int heap_id)
{
    struct Strbuf *buf = STRBUF_Create(8, (u16)heap_id);
    MYSTATUS_NameToStrbuf(name, buf);
    return buf;
}


void MYSTATUS_SetId(struct MyStatus *mystatus, u32 id)
{
    mystatus->id = id;
}

u32 MYSTATUS_GetId(const struct MyStatus *mystatus)
{
    return mystatus->id;
}

u16 MYSTATUS_GetIdLow16(const struct MyStatus *mystatus)
{
    return (u16)mystatus->id;
}

u32 MYSTATUS_GetProfileId(const struct MyStatus *mystatus)
{
    return mystatus->profile_id;
}

/* Set once: the store is skipped when the field is already non-zero. */
void MYSTATUS_SetProfileIdOnce(struct MyStatus *mystatus, u32 profile_id)
{
    if (mystatus->profile_id == 0) {
        mystatus->profile_id = profile_id;
    }
}

void MYSTATUS_SetOutfitVariant(struct MyStatus *mystatus, u8 outfit_variant)
{
    mystatus->outfit_variant = outfit_variant;
}

u8 MYSTATUS_GetOutfitVariant(const struct MyStatus *mystatus)
{
    return mystatus->outfit_variant;
}

u8 MYSTATUS_GetOutfit(const struct MyStatus *mystatus)
{
    return mystatus->outfit;
}

void MYSTATUS_SetOutfit(struct MyStatus *mystatus, u8 outfit)
{
    mystatus->outfit = outfit;
}

u8 MYSTATUS_GetAvatarId(const struct MyStatus *mystatus)
{
    return mystatus->avatar_id;
}

void MYSTATUS_SetAvatarId(struct MyStatus *mystatus, u8 avatar_id)
{
    mystatus->avatar_id = avatar_id;
}

u8 MYSTATUS_GetGender(const struct MyStatus *mystatus)
{
    return mystatus->gender;
}

void MYSTATUS_SetGender(struct MyStatus *mystatus, u8 gender)
{
    mystatus->gender = gender;
}

u8 MYSTATUS_GetLanguage(const struct MyStatus *mystatus)
{
    return mystatus->language;
}

u8 MYSTATUS_GetVersion(const struct MyStatus *mystatus)
{
    return mystatus->version;
}

void MYSTATUS_SetLanguageAndVersion(struct MyStatus *mystatus, u8 language, u8 version)
{
    mystatus->language = language;
    mystatus->version = version;
}


/*
 * Play-time counter: hours (saturating at 999), minutes, seconds and language packed
 * calendar stamp.  The stamp widths agree three ways: the AND masks in
 * PLAYTIME_Init, the shift pairs in the getters at 0x020086C8 and on, and the
 * RTCDate / RTCTime fields that PLAYTIME_SetStampNow feeds it from.
 *
 * The four unsigned divisions in PLAYTIME_AddSeconds compile to calls to the
 * compiler runtime helper _u32_div_f (0x0209C2B0).  `language / version` and `language % version` on
 * the same operands give two separate calls: the helper returns the quotient
 * in r0 and the remainder in r1, but the compiler does not common them up.
 */
void *PLAYTIME_Create(u32 heap_id)
{
    struct PlayTime *playtime = func_02030734(heap_id, sizeof(struct PlayTime), 1,
                                       playtime_file_name, 32);
    PLAYTIME_Init(playtime);
    return playtime;
}


void PLAYTIME_Init(struct PlayTime *playtime)
{
    playtime->hours        = 0;
    playtime->minutes      = 0;
    playtime->seconds      = 0;
    playtime->stamp.year   = 0;
    playtime->stamp.month  = 0;
    playtime->stamp.day    = 0;
    playtime->stamp.hour   = 0;
    playtime->stamp.minute = 0;
}

/* Add `seconds_to_add` seconds, carrying into minutes and hours and saturating at
 * 999:59:59.  The leading guard is the saturation test: once the counter is
 * full the object is left untouched. */
void PLAYTIME_AddSeconds(struct PlayTime *playtime, u32 seconds_to_add)
{
    u32 hours, minutes, seconds;

    hours = playtime->hours;
    if (hours == 999 && playtime->minutes == 59 && playtime->seconds == 59) {
        return;
    }
    seconds = playtime->seconds + seconds_to_add;
    minutes = playtime->minutes;
    if (seconds > 59) {
        minutes += seconds / 60;
        seconds = seconds % 60;
        if (minutes > 59) {
            hours += minutes / 60;
            minutes = minutes % 60;
            if (hours >= 999) {
                hours = 999;
                minutes = 59;
                seconds = 59;
            }
        }
    }
    playtime->hours   = hours;
    playtime->minutes = minutes;
    playtime->seconds = seconds;
}

void PLAYTIME_Copy(struct PlayTime *dest, const struct PlayTime *src)
{
    MI_CpuCopy8(src, dest, sizeof(struct PlayTime));
}

u16 PLAYTIME_GetHours(const struct PlayTime *playtime)
{
    return playtime->hours;
}

u8 PLAYTIME_GetMinutes(const struct PlayTime *playtime)
{
    return playtime->minutes;
}

u8 PLAYTIME_GetSeconds(const struct PlayTime *playtime)
{
    return playtime->seconds;
}

/* Stamp the object with the wall clock. */
void PLAYTIME_SetStampNow(struct PlayTime *playtime)
{
    struct RTCDate date;
    struct RTCTime time;

    RTC_GetDate(&date);
    RTC_GetTime(&time);

    playtime->stamp.year   = date.year;
    playtime->stamp.month  = date.month;
    playtime->stamp.day    = date.day;
    playtime->stamp.hour   = time.hour;
    playtime->stamp.minute = time.minute;
}

u32 PLAYTIME_GetStampYear(const struct PlayTime *playtime)
{
    return playtime->stamp.year;
}

u32 PLAYTIME_GetStampMonth(const struct PlayTime *playtime)
{
    return playtime->stamp.month;
}

u32 PLAYTIME_GetStampDay(const struct PlayTime *playtime)
{
    return playtime->stamp.day;
}

u32 PLAYTIME_GetStampHour(const struct PlayTime *playtime)
{
    return playtime->stamp.hour;
}

u32 PLAYTIME_GetStampMinute(const struct PlayTime *playtime)
{
    return playtime->stamp.minute;
}

void PLAYTIME_GetStamp(const struct PlayTime *playtime, struct PlayTimeStamp *out)
{
    *out = playtime->stamp;
}

void PLAYTIME_SetStamp(struct PlayTime *playtime, const struct PlayTimeStamp *in)
{
    playtime->stamp = *in;
}


/*
 * Save block 0x1B.  Every accessor reaches the block with
 * SAVE_CONTROL_GetBlock(save, 0x1B).  The block holds a Config, a MyStatus and a
 * PlayTime, then a flag byte, a table of marks and a table of words.
 *
 * SYSTEM_DATA_SetMyStatus and SYSTEM_DATA_CopyMyStatus copy the 0x20-byte MyStatus with four ldm/stm
 * pairs: mwccarm inlines an aggregate copy of this size, using the padded
 * sizeof (0x20).  SYSTEM_DATA_GetConfig is a tail call through a pool word with the
 * second argument set up first.
 */
u32 SYSTEM_DATA_GetSize(void)
{
    return sizeof(struct SystemData);
}


void SYSTEM_DATA_Init(struct SystemData *sys_data)
{
    MIi_CpuClear32(0, sys_data, sizeof(struct SystemData));
    CONFIG_Init(&sys_data->config);
    MYSTATUS_Init(&sys_data->mystatus);
    PLAYTIME_Init(&sys_data->playtime);
    sys_data->active = 0;
}

struct MyStatus *SYSTEM_DATA_GetMyStatus(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return &sys_data->mystatus;
}

struct Config *SYSTEM_DATA_GetConfig(void *save)
{
    return SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
}

struct PlayTime *SYSTEM_DATA_GetPlayTime(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return &sys_data->playtime;
}

u8 SYSTEM_DATA_IsActive(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return sys_data->active;
}

void SYSTEM_DATA_SetActive(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->active = 1;
}

void SYSTEM_DATA_ClearActive(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->active = 0;
}

int SYSTEM_DATA_IsMarked(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    if (sys_data->marks[index] == 0xC21E) {
        return 1;
    }
    return 0;
}

void SYSTEM_DATA_SetMark(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->marks[index] = 0xC21E;
}

void SYSTEM_DATA_ClearMark(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->marks[index] = 0;
}

u32 *SYSTEM_DATA_GetWordSlot(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return &sys_data->words[index];
}

void SYSTEM_DATA_SetMyStatus(void *save, const struct MyStatusHolder *src)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->mystatus = src->mystatus;
}

void SYSTEM_DATA_CopyMyStatus(void *save, struct MyStatusHolder *dest)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    dest->mystatus = sys_data->mystatus;
}


/*
 * Save block 0x1C, 0x9C bytes.  The record at +0x80 and the buffer
 * PLAYER_LOCATION_SetRecordFromBuffer fills it from are different types: the record's +0x1A comes
 * from the buffer's +0x1B, and the record's +0x1B from the buffer's +0x40, a
 * word truncated to a byte.  As one struct assignment the function collapses
 * to an ldm/stm run and is 80 bytes short.  The record's +0x18 is signed
 * (`movs r0, #0x98; ldrsh` in PLAYER_LOCATION_CopyRecordToBuffer, since ldrsh has no immediate
 * form) and the buffer's is not.
 */
u32 PLAYER_LOCATION_GetSize(void)
{
    return sizeof(struct PlayerLocationData);
}


void PLAYER_LOCATION_Init(struct PlayerLocationData *location_data)
{
    MI_CpuFill8(location_data, 0, sizeof(struct PlayerLocationData));
    location_data->zone_id = 0x1AB;
}

void PLAYER_LOCATION_Nop(void)
{
}

void *PLAYER_LOCATION_GetLocationA(struct PlayerLocationData *location_data)
{
    return location_data->location_a;
}

void *PLAYER_LOCATION_GetLocationB(struct PlayerLocationData *location_data)
{
    return location_data->location_b;
}

void *PLAYER_LOCATION_GetShortData(struct PlayerLocationData *location_data)
{
    return location_data->short_data;
}

struct PlayerLocationData *PLAYER_LOCATION_GetData(void *save)
{
    return SAVE_CONTROL_GetBlock(save, BLOCK_ID_1C);
}

void PLAYER_LOCATION_SetRecordFromBuffer(void *save, const struct LocationRecordBuf *src)
{
    struct PlayerLocationData *location_data = PLAYER_LOCATION_GetData(save);

    location_data->record.zone_id = src->zone_id;
    location_data->record.position = src->position;
    location_data->record.facing = src->facing;
    location_data->record.entrance_id = src->entrance_id;
    location_data->record.form = src->form;
    location_data->record.look = src->look;
    location_data->record.height_offset = src->height_offset;
    location_data->record.kind = src->flags;
    location_data->record.flags = src->flags_word;
}

void PLAYER_LOCATION_CopyRecordToBuffer(void *save, struct LocationRecordBuf *dest)
{
    struct PlayerLocationData *location_data = PLAYER_LOCATION_GetData(save);

    dest->zone_id = location_data->record.zone_id;
    dest->position = location_data->record.position;
    dest->facing = location_data->record.facing;
    dest->entrance_id = location_data->record.entrance_id;
    dest->form = location_data->record.form;
    dest->look = location_data->record.look;
    dest->height_offset = location_data->record.height_offset;
    dest->flags = location_data->record.kind;
    dest->flags_word = location_data->record.flags;
}

void PLAYER_LOCATION_CopyRecord(void *save, struct LocationRecord *dest)
{
    struct PlayerLocationData *location_data = PLAYER_LOCATION_GetData(save);

    *dest = location_data->record;
}

/* The getter/setter pair on some other object's byte at +6, through which the
 * +0x72 field of this block is exchanged (FIELD_STATUS_IsFlashActive and FIELD_STATUS_SetFlashActive, two
 * four-byte leaves in a literal-pool run). */
void PLAYER_LOCATION_ReadStyleFrom(struct PlayerLocationData *location_data, const void *src)
{
    location_data->style = FIELD_STATUS_IsFlashActive(src);
}

void PLAYER_LOCATION_WriteStyleTo(const struct PlayerLocationData *location_data, void *dest)
{
    FIELD_STATUS_SetFlashActive(dest, location_data->style);
}

void PLAYER_LOCATION_SetFlagA(struct PlayerLocationData *location_data, u8 value)
{
    location_data->flag_a = value;
}

void PLAYER_LOCATION_GetFlagA(const struct PlayerLocationData *location_data, u8 *out)
{
    *out = location_data->flag_a;
}

void PLAYER_LOCATION_SetFlagB(struct PlayerLocationData *location_data, u8 value)
{
    location_data->flag_b = value;
}

void PLAYER_LOCATION_GetFlagB(const struct PlayerLocationData *location_data, u8 *out)
{
    *out = location_data->flag_b;
}

void PLAYER_LOCATION_SetCounter(struct PlayerLocationData *location_data, u32 value)
{
    location_data->counter = value;
}

void PLAYER_LOCATION_GetCounter(const struct PlayerLocationData *location_data, u32 *out)
{
    *out = location_data->counter;
}

u16 PLAYER_LOCATION_GetValueA(const struct PlayerLocationData *location_data)
{
    return location_data->value_a;
}

void PLAYER_LOCATION_SetValueA(struct PlayerLocationData *location_data, u16 value)
{
    location_data->value_a = value;
}

void PLAYER_LOCATION_SetValueB(struct PlayerLocationData *location_data, u16 value)
{
    location_data->value_b = value;
}

u16 PLAYER_LOCATION_GetValueB(const struct PlayerLocationData *location_data)
{
    return location_data->value_b;
}

u16 PLAYER_LOCATION_GetZoneId(const struct PlayerLocationData *location_data)
{
    return location_data->zone_id;
}

void PLAYER_LOCATION_SetZoneId(struct PlayerLocationData *location_data, u16 value)
{
    location_data->zone_id = value;
}

# The language cartridges

Pokémon Black and White were sold in one cartridge per language. The English cartridge
(USA, Europe) is the reference: its layout is `layout/` and every address in `src/game` is an
English Black address. The same source builds the French, German, Italian and Spanish
cartridges of both games, byte-identical to the dumps in [ROMS.md](ROMS.md).

## How much differs

Measured against the English cartridge of the same game:

- The file system has the same 247 files in the same order. 51 to 57 files hold other content
  (text, fonts, graphics with text). The two download-play images carry the language in their
  name.
- The ARM9 module is 64 to 256 bytes shorter, so every overlay loads lower. 4 to 10 overlays
  change size.
- About 140 functions differ. About 40 of them only load the language id. The DSi code is the
  same in every cartridge.
- Black and White differ in the same places in every language, so the version and the
  language are two independent switches.

## The source

`src/game/version.h` defines the switches. The tools pass them from the target
(`tools/targets.py`):

| Name | Meaning |
|---|---|
| `VERSION` | `VERSION_BLACK` (default) or `VERSION_WHITE` |
| `LANGUAGE` | `LANGUAGE_ENGLISH` (default), `_FRENCH` 3, `_ITALIAN` 4, `_GERMAN` 5, `_SPANISH` 7 (`_JAPANESE` 1) |
| `PM_LANG_ID` | the cartridge's language id, stored in the player record, profiles, mail and Wi-Fi data |
| `PM_LANG_MONTH_AS_NAME` | French, Italian and German write a month as its name in dates |
| `PM_LANG_VERSION_KEY` | the Wi-Fi match key: language and version |

A site that differs in one file uses a constant chosen by an `#if LANGUAGE` chain near the top
of the file, with the English value in the `#else`. Most are text positions and widths. A few
are real code: the glyph decoder of French, German and Italian (`gf_font.c`), the species-name
setters of the word set (`wordset.c`), the plural rules of item messages
(`scrcmd_proc_fld.c`), the size of the easy-chat search result list (`pmsi_search.c`) and the
similar-word group count (`pms_word.c`).

A value that differs between the European cartridges is written `PM_LANG_EU(english, french,
german, italian, spanish)`, and code that differs is an `if (PM_LANGUAGE_IS(LANGUAGE_FRENCH))`.
On the DS both are constants, so the compiler keeps only the target's branch. A Japanese value
that differs keeps its own `#if LANGUAGE == LANGUAGE_JAPANESE` branch.

### One PC build for every European cartridge

A PC build that defines neither `__MWERKS__` nor `LANGUAGE` reads the language at run time:
`PM_LANGUAGE_RUNTIME` is 1, `PM_LANGUAGE_IS` and `PM_LANG_ID` read `g_pm_language`, and the
port defines that variable and sets it from the cartridge before the game's first frame. The
build has the English layout; arrays sized per language take the largest size
(`PMSI_SEARCH_RESULT_CAP`). Japanese is not part of this choice.

The game works the same way: a PC build that defines neither `__MWERKS__` nor `VERSION` reads
it from `g_pm_version` (`VERSION_BLACK` or `VERSION_WHITE`). `PM_VERSION_IS(version)` tests it,
`PM_VERSION_BW(black, white)` picks a value, and `PM_VERSION_ID`, `MSG_PROFANITY_NOTICE`,
`PM_VERSION_BIT`, `PM_VERSION_MASK` and `PM_VERSION_LEGEND_SPECIES` follow it.

`python tools/langmap.py` writes the address maps the port needs, after `romlink.py --relink`
of the targets:

- `layout/langmap/<target>.tsv`: runs of English Black addresses that move by one amount in the
  target (region, English start, English end, target start, owner). Rows inside the region's own
  place are its own rows (owner is the region). Rows outside it are reference rows. Each one is
  the run of another region that the region links to or that its data points at (owner is that
  region, or `?` for an object that no region owns). A reference row never spans two overlays.
  Overlays that share a window can each have a reference row over the same address. The row of
  the overlay loaded with the region is the one that holds.
- `layout/langmap/word_pairs.tsv`: pointer words in a region's data that the rows do not map:
  target, region, the English value and the target value. These words point into the middle of
  data with another layout, or into data with no object of the same name. The file also lists
  every word whose target value falls in more than one of the region's rows with different
  English results (overlays that share a window). For such a word, the target value alone
  cannot give the English address. Every other pointer word in data of the same size has
  exactly one row that gives it, with the right shift.
- `layout/langmap/size_changed.tsv`: objects whose size differs from English, with both
  addresses and sizes. The port takes them from the target's ROM.
- `layout/langmap/size_changed_ptrs.tsv`: the pointer words of those data objects in the target
  (offset in the object, the address the word holds). `reloc` rows come from the link's
  relocations; `scan` rows are aligned words that hold a main-memory address, for objects the
  link took as one block of the target's bytes.
- `layout/langmap/not_mapped.tsv`: English data objects that have no object of the same name in
  the target (data the target's link places by content and cuts differently, and secure-area
  pieces). A pointer into one of them has no run; the port takes that data from the target.
- `build/langmap/<target>.tsv`: the full table, one row per object (not committed).

## The tools

Every link and ROM tool takes `--target NAME` or `ALETHEIA_TARGET`. Addresses are planned in
English Black and mapped to the target (`tools/white_map.py`): by aligning the two images, and
by the symbol maps of the regions that already link for that target. The data after the code
is generated from the target's own extract with English Black's object structure; tables whose
size changes per language (the easy-chat word lists, some Pokédex arrays) are taken as one block
from the target. `romlink.py --relink` links a region that failed a second time, after the
regions whose addresses it uses have linked.

## Japanese

The Japanese cartridges (`black_ja`, `white_ja`) are an earlier build of the same program. The
source builds both byte-identical ([ROMS.md](ROMS.md)).

- About 95 percent of the functions are the same or differ only in addresses. The rest differ in
  one or two words (line numbers, message archive ids, digit width, the language id 1) or in
  length (older code, Japan-only behaviour, structs with fewer fields).
- Every message has two blocks, kana and kanji. The options menu has a sixth setting for it
  (`CONFIG_GetTextLanguage`, `CONFIG_SetTextLanguage`). A name is 5 characters, not 10.
- A failed check passes the file name, the line and a message string, where the other
  languages pass empty strings. The heap allocations of a file use the same file-name string.

`version.h` has three more names for these sites:

| Name | Meaning |
|---|---|
| `PM_SRC_LINE(english, japanese)` | a source line number (failed checks, heap allocations) |
| `PM_LANG_JA(english, japanese)` | any other value that differs only in Japanese |
| `PM_LANG_HALF_WIDTH_DIGITS` | the digit width of word-set numbers: 0 in Japanese, 1 otherwise |

Data that only Japanese has (the file-name and message strings of failed checks, some tables)
is declared as `<prefix>_ja_<address>` with its Japanese Black address, under
`#if LANGUAGE == LANGUAGE_JAPANESE`. The link places these names in both Japanese targets.
A function that only one language has is guarded with its callers.

The data after the code is placed by content (`tools/jatail.py`): each object of English Black
is searched in the target's tail. An object that the code references is pinned first, by the
literal pools of the functions whose code matches (`white_map.ja_pool_map`). The ARM9 data
(`tools/arm9data.py`) is placed the same way. A few objects that no pool of the listings places
are found from a first data-mode link: where the linked code loads another address than the
target's code at the same place, `tools/jafix.py` records the target's address, and the next
link uses it. `romlink.py --relink` runs these passes itself for the Japanese targets.


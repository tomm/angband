#ifndef INCLUDED_DEFINES_H
#define INCLUDED_DEFINES_H

/*
 * Copyright (c) 1997 Ben Harrison, James E. Wilson, Robert A. Koeneke
 *
 * This software may be copied and distributed for educational, research,
 * and not for profit purposes provided that this copyright and statement
 * are included in all such copies.  Other copyrights may also apply.
 */

/*
 * Do not edit this file unless you know *exactly* what you are doing.
 *
 * Some of the values in this file were chosen to preserve game balance,
 * while others are hard-coded based on the format of old save-files, the
 * definition of arrays in various places, mathematical properties, fast
 * computation, storage limits, or the format of external text files.
 *
 * Changing some of these values will induce crashes or memory errors or
 * savefile mis-reads.  Most of the comments in this file are meant as
 * reminders, not complete descriptions, and even a complete knowledge
 * of the source may not be sufficient to fully understand the effects
 * of changing certain definitions.
 *
 * Lastly, note that the code does not always use the symbolic constants
 * below, and sometimes uses various hard-coded values that may not even
 * be defined in this file, but which may be related to definitions here.
 * This is of course bad programming practice, but nobody is perfect...
 *
 * You have been warned.
 */


/*
 * Number of grids in each block (vertically)
 * Probably hard-coded to 11, see "generate.c"
 */
#define BLOCK_HGT	11

/*
 * Number of grids in each block (horizontally)
 * Probably hard-coded to 11, see "generate.c"
 */
#define BLOCK_WID	11

/**
 * Number of grids in each panel (vertically)
 */
#define PANEL_HGT	((int)(BLOCK_HGT / tile_height))

/**
 * Number of grids in each panel (horizontally)
 */
#define PANEL_WID 	((int)(BLOCK_WID / tile_width))


/*
 * Number of grids in each dungeon (vertically)
 * Must be a multiple of SCREEN_HGT
 * Must be less or equal to 256
 */
#define DUNGEON_HGT		66

/*
 * Number of grids in each dungeon (horizontally)
 * Must be a multiple of SCREEN_WID
 * Must be less or equal to 256
 */
#define DUNGEON_WID		198

#define TOWN_WID 66
#define TOWN_HGT 22


/* Maximum number of Angband windows */
#define ANGBAND_TERM_MAX 8

/* The fixed amount of energy a player should have at the start of a new level */
#define INITIAL_DUNGEON_ENERGY 100


/*
 * Maximum dungeon level.  The player can never reach this level
 * in the dungeon, and this value is used for various calculations
 * involving object and monster creation.  It must be at least 100.
 * Setting it below 128 may prevent the creation of some objects.
 */
#define MAX_DEPTH	128

/*
 * Misc constants
 */
#define TOWN_DAWN		10000	/* Number of turns from dawn to dawn */
#define TOWN_DUSK         5000    /* Number of turns from dawn to dusk */
#define BREAK_GLYPH		550	/* Rune of protection resistance */
#define BTH_PLUS_ADJ    	3 	/* Adjust BTH per plus-to-hit */
#define MON_MULT_ADJ		8 	/* High value slows multiplication */
#define MON_DRAIN_LIFE		2	/* Percent of player exp drained per hit */


/*
 * More maximum values
 */
#define MAX_SIGHT_LGE   20      /* Maximum view distance */
#define MAX_RANGE_LGE   20      /* Maximum projection range */
#define MAX_SIGHT_SML   10      /* Maximum view distance (small devices) */
#define MAX_RANGE_SML   10      /* Maximum projection range (small devices) */
#define MAX_SIGHT (OPT(birth_small_range) ? MAX_SIGHT_SML : MAX_SIGHT_LGE)  
#define MAX_RANGE (OPT(birth_small_range) ? MAX_RANGE_SML : MAX_RANGE_LGE)


/** Monster generation info **/

/* There is a 1/500 chance per round of creating a new monster */
#define MAX_M_ALLOC_CHANCE	500

/* Normal levels get at least 14 monsters */
#define MIN_M_ALLOC_LEVEL	14

/* The town starts out with 4 residents during the day */
#define MIN_M_ALLOC_TD		4

/* The town starts out with 8 residents during the night */
#define MIN_M_ALLOC_TN		8

/*
 * A monster can only "multiply" (reproduce) if there are fewer than 100
 * monsters on the level capable of such spontaneous reproduction.  This
 * is a hack which prevents the "mon_list[]" array from exploding due to
 * reproducing monsters.  Messy, but necessary.
 */
#define MAX_REPRO	100


/** UI constants **/

/* 
 * Special values for the number of turns to rest, these need to be
 * negative numbers, as postive numbers are taken to be a turncount,
 * and zero means "not resting". 
 */
enum 
{
	REST_COMPLETE = -2,
	REST_ALL_POINTS = -1,
	REST_SOME_POINTS = -3
};

/**
 * Minimum number of turns required for regeneration to kick in during resting.
 */
#define REST_REQUIRED_FOR_REGEN 5

/*** General index values ***/

/*** Important artifact indexes (see "lib/edit/artifact.txt") ***/

#define ART_POWER			13
#define ART_MORGOTH			34
#define ART_GROND			111
#define ART_PALANTIR			7

/*
 * Hack -- first "normal" artifact in the artifact list.  All of
 * the artifacts with indexes from 1 to 15 are "special" (lights,
 * rings, amulets), and the ones from 16 to 127 are "normal".
 */
#define ART_MIN_NORMAL		16



/*** Player flags ***/


/*
 * Bit flags for the "p_ptr->notice" variable
 */
#define PN_COMBINE      0x00000001L    /* Combine the pack */
#define PN_REORDER      0x00000002L    /* Reorder the pack */
#define PN_AUTOINSCRIBE 0x00000004L    /* Autoinscribe items */
#define PN_PICKUP       0x00000008L    /* Pick stuff up */
#define PN_SQUELCH      0x00000010L    /* Squelch stuff */
#define PN_SORT_QUIVER  0x00000020L    /* Sort the quiver */
#define PN_MON_MESSAGE	0x00000040L	   /* flush monster pain messages */
/* xxx (many) */


/*
 * Bit flags for the "p_ptr->update" variable
 */
#define PU_BONUS		0x00000001L	/* Calculate bonuses */
#define PU_TORCH		0x00000002L	/* Calculate torch radius */
/* xxx (many) */
#define PU_HP			0x00000010L	/* Calculate chp and mhp */
#define PU_MANA			0x00000020L	/* Calculate csp and msp */
#define PU_SPELLS		0x00000040L	/* Calculate spells */
/* xxx (many) */
#define PU_FORGET_VIEW	0x00010000L	/* Forget field of view */
#define PU_UPDATE_VIEW	0x00020000L	/* Update field of view */
/* xxx (many) */
#define PU_FORGET_FLOW	0x00100000L	/* Forget flow data */
#define PU_UPDATE_FLOW	0x00200000L	/* Update flow data */
/* xxx (many) */
#define PU_MONSTERS		0x10000000L	/* Update monsters */
#define PU_DISTANCE		0x20000000L	/* Update distances */
/* xxx */
#define PU_PANEL		0x80000000L	/* Update panel */


/*
 * Bit flags for the "p_ptr->redraw" variable
 */
#define PR_MISC			0x00000001L	/* Display Race/Class */
#define PR_TITLE		0x00000002L	/* Display Title */
#define PR_LEV			0x00000004L	/* Display Level */
#define PR_EXP			0x00000008L	/* Display Experience */
#define PR_STATS		0x00000010L	/* Display Stats */
#define PR_ARMOR		0x00000020L	/* Display Armor */
#define PR_HP			0x00000040L	/* Display Hitpoints */
#define PR_MANA			0x00000080L	/* Display Mana */
#define PR_GOLD			0x00000100L	/* Display Gold */

#define PR_HEALTH		0x00000800L	/* Display Health Bar */
#define PR_SPEED		0x00001000L	/* Display Extra (Speed) */
#define PR_STUDY		0x00002000L	/* Display Extra (Study) */
#define PR_DEPTH		0x00004000L	/* Display Depth */
#define PR_STATUS		0x00008000L
#define PR_DTRAP		0x00010000L /* Trap detection indicator */
#define PR_STATE		0x00020000L	/* Display Extra (State) */
#define PR_MAP			0x00040000L	/* Redraw whole map */

#define PR_INVEN		0x00080000L /* Display inven/equip */
#define PR_EQUIP		0x00100000L /* Display equip/inven */
#define PR_MESSAGE		0x00200000L /* Display messages */
#define PR_MONSTER		0x00400000L /* Display monster recall */
#define PR_OBJECT		0x00800000L /* Display object recall */
#define PR_MONLIST		0x01000000L /* Display monster list */
/* xxx */
#define PR_ITEMLIST     0x04000000L /* Display item list */

/* Display Basic Info */
#define PR_BASIC \
	(PR_MISC | PR_TITLE | PR_STATS | PR_LEV |\
	 PR_EXP | PR_GOLD | PR_ARMOR | PR_HP |\
	 PR_MANA | PR_DEPTH | PR_HEALTH | PR_SPEED)

/* Display Extra Info */
#define PR_EXTRA \
	(PR_STATUS | PR_STATE | PR_STUDY)


/*
 * Bit flags for the "p_ptr->window" variable.
 */
#define PW_INVEN            0x00000001L /* Display inven/equip */
#define PW_EQUIP            0x00000002L /* Display equip/inven */
#define PW_PLAYER_0         0x00000004L /* Display player (basic) */
#define PW_PLAYER_1         0x00000008L /* Display player (extra) */
#define PW_PLAYER_2         0x00000010L /* Display player (compact) */
#define PW_MAP              0x00000020L /* Display dungeon map */
#define PW_MESSAGE          0x00000040L /* Display messages */
#define PW_OVERHEAD         0x00000080L /* Display overhead view */
#define PW_MONSTER          0x00000100L /* Display monster recall */
#define PW_OBJECT           0x00000200L /* Display object recall */
#define PW_MONLIST          0x00000400L /* Display monster list */
#define PW_STATUS           0x00000800L /* Display status */
#define PW_ITEMLIST         0x00001000L /* Display item list */
/* xxx */
#define PW_BORG_1           0x00004000L /* Display borg messages */
#define PW_BORG_2           0x00008000L /* Display borg status */


#define PW_MAX_FLAGS		16


/*** Cave flags ***/

/* 
 * Information for Feelings 
 */
#define FEELING_TOTAL		100		/* total number of feeling squares per level */ 
#define FEELING1		10		/* Squares needed to see in order to trigger first feeling */

/*
 * Chest trap flags (see "object/chest.c")
 */
#define CHEST_LOSE_STR	0x01
#define CHEST_LOSE_CON	0x02
#define CHEST_POISON	0x04
#define CHEST_PARALYZE	0x08
#define CHEST_EXPLODE	0x10
#define CHEST_SUMMON	0x20


/*** Macro Definitions ***/

/*
 * Hack -- The main "screen"
 */
#define term_screen	(angband_term[0])

/*
 * Convert a "location" (Y,X) into a "grid" (G)
 */
#define GRID(Y,X) \
	(256 * (Y) + (X))

/*
 * Convert a "grid" (G) into a "location" (Y)
 */
#define GRID_Y(G) \
	((int)((G) / 256U))

/*
 * Convert a "grid" (G) into a "location" (X)
 */
#define GRID_X(G) \
	((int)((G) % 256U))


/*
 * Convert a "key event" into a "location" (Y)
 */
#define KEY_GRID_Y(K) \
  ((int) (((K.mouse.y - ROW_MAP) / tile_height) + Term->offset_y))

/*
 * Convert a "key event" into a "location" (X)
 */
#define KEY_GRID_X(K) \
	((int) (((K.mouse.x - COL_MAP) / tile_width) + Term->offset_x))


/*
 * Determine if a "legal" grid is within "los" of the player
 *
 * Note the use of comparison to zero to force a "boolean" result
 */
#define player_has_los_bold(Y,X) \
	(sqinfo_has(cave->info[Y][X], SQUARE_VIEW))


/*
 * Determine if a "legal" grid can be "seen" by the player
 *
 * Note the use of comparison to zero to force a "boolean" result
 */
#define player_can_see_bold(Y,X) \
	(sqinfo_has(cave->info[Y][X], SQUARE_SEEN))


/*
 * Say whether it's daytime or not
 */
#define is_daytime() \
	(((turn % (10L * TOWN_DAWN)) < ((10L * TOWN_DAWN) / 2)) ? FALSE : TRUE)


#define SCAN_INSTANT ((u32b) -1)
#define SCAN_OFF 0
#define SCAN_MACRO 45

#define MAX_ITEMLIST 2560

/**
 * Maximum number of rvals (monster templates) that a pit can specify.
 */
#define MAX_RVALS 4


#endif /* !INCLUDED_DEFINES_H */

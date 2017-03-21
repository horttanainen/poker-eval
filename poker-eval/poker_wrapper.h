/*
 *  Copyright 2006 Loic Dachary <loic@dachary.org> 
 *
 * This program gives you software freedom; you can copy, convey,
 * propagate, redistribute and/or modify this program under the terms of
 * the GNU General Public License (GPL) as published by the Free Software
 * Foundation (FSF), either version 3 of the License, or (at your option)
 * any later version of the GPL published by the FSF.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program in a file in the toplevel directory called "GPLv3".
 * If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __POKER_WRAPPER_H__
#define __POKER_WRAPPER_H__

#include "poker-eval/pokereval_export.h"

#include "poker-eval/deck_std.h"

POKEREVAL_EXPORT unsigned int wrap_StdDeck_N_CARDS(void);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_MASK(int index);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_2(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_3(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_4(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_5(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_6(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_7(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_8(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_9(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_TEN(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_JACK(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_QUEEN(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_KING(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_ACE(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_COUNT(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_FIRST(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Rank_LAST(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_RANK(unsigned int index);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_SUIT(unsigned int index);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_MAKE_CARD(unsigned int rank, unsigned int suit);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_HEARTS(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_DIAMONDS(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_CLUBS(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_SPADES(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_FIRST(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_LAST(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_Suit_COUNT(void);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_CardMask_SPADES(StdDeck_CardMask cm);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_CardMask_CLUBS(StdDeck_CardMask cm);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_CardMask_DIAMONDS(StdDeck_CardMask cm);
POKEREVAL_EXPORT unsigned int wrap_StdDeck_CardMask_HEARTS(StdDeck_CardMask cm);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_SET_HEARTS(StdDeck_CardMask cm, unsigned int ranks);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_SET_DIAMONDS(StdDeck_CardMask cm, unsigned int ranks);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_SET_CLUBS(StdDeck_CardMask cm, unsigned int ranks);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_SET_SPADES(StdDeck_CardMask cm, unsigned int ranks);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_NOT(StdDeck_CardMask cm);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_OR(StdDeck_CardMask op1, StdDeck_CardMask op2);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_AND(StdDeck_CardMask op1, StdDeck_CardMask op2);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_XOR(StdDeck_CardMask op1, StdDeck_CardMask op2);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_SET(StdDeck_CardMask mask, unsigned int index);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_UNSET(StdDeck_CardMask mask, unsigned int index);
POKEREVAL_EXPORT int wrap_StdDeck_CardMask_CARD_IS_SET(StdDeck_CardMask mask, unsigned int index);
POKEREVAL_EXPORT int wrap_StdDeck_CardMask_ANY_SET(StdDeck_CardMask mask1, StdDeck_CardMask mask2);
POKEREVAL_EXPORT StdDeck_CardMask wrap_StdDeck_CardMask_RESET(void);
POKEREVAL_EXPORT int wrap_StdDeck_CardMask_IS_EMPTY(StdDeck_CardMask mask);
POKEREVAL_EXPORT int wrap_StdDeck_CardMask_EQUAL(StdDeck_CardMask mask1, StdDeck_CardMask mask2);

#endif /* __POKER_WRAPPER_H__ */

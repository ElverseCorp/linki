#ifndef LINKI_H_
#define LINKI_H_

/**************************************************************************//**
 * @file     linki.h
 * @brief    Project L - Linki, cross-platform web library.
 * @version  V0.0.1
 * @date     28. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/*
 * Linki library.
 * Linki, cross-platform web library.
 *
 * Author: Matvey Rybalkin
 * Contact: robotsvision.vx@gmail.com (github.com TheProjectL/linki)
 * Date: 28 August. 2024
 *
 * This file is part of Linku library. And this project is a part of Project L.
 *
 * Llibs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * Llibs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Llibs. If not, see <http://www.gnu.org/licenses/>.
 */

/* Requires at least C11 */
#if __STDC_VERSION__  >= 201112L

/* Include native headers */
#include <socket.h>

#else
#error [linki.h]: Requires at least version C 2011 (__STDC_VERSION__ >= 201112L)
#endif
#endif // LINKI_H_
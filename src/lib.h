/*
 * libefivar - library for the manipulation of EFI variables
 * Copyright 2012-2013 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBEFIVAR_LIB_H
#define LIBEFIVAR_LIB_H 1

#include "efivar.h"

#define GUID_FORMAT "%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x"

struct efi_var_operations {
	int (*probe)(void);
	int (*set_variable)(efi_guid_t guid, const char *name, uint8_t *data,
			    size_t data_size, uint32_t attributes);
	int (*del_variable)(efi_guid_t guid, const char *name);
	int (*get_variable)(efi_guid_t guid, const char *name, uint8_t **data,
			    size_t *data_size, uint32_t *attributes);
	int (*get_variable_attributes)(efi_guid_t guid, const char *name,
				       uint32_t *attributes);
	int (*get_variable_size)(efi_guid_t guid, const char *name,
				 size_t *size);
	int (*get_next_variable_name)(efi_guid_t **guid, char **name);
	int (*append_variable)(efi_guid_t guid, const char *name,
			       uint8_t *data, size_t data_size,
			       uint32_t attributes);
};

typedef unsigned long efi_status_t;

extern struct efi_var_operations vars_ops;
extern struct efi_var_operations efivarfs_ops;

#endif /* LIBEFIVAR_LIB_H */

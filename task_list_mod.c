/*
 *  task_list_mod.c - list tasks from kernel modulede
 *
 *  Copyright (C) 2019 Blade Runner Labs LTD.
 *  Author: Yan Vugenfirer, yan@bladerunner.io
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init_task.h>

static int __init list_tasks_init_module(void)
{
	struct task_struct *task = &init_task;

	/* Walk through the task list, until we hit the init_task_again */
	do {
		printk( KERN_INFO "*** %s [%d] parent %s\n",
				task->comm, task->pid, task->parent->comm);
	} while ((task = next_task(task)) != &init_task);

	return 0;
}

static void __exit list_tasks_exit_module(void)
{
	printk("Exiting the module!");
}

module_init(list_tasks_init_module);
module_exit(list_tasks_exit_module);

MODULE_AUTHOR("Yan Vugenfirer <yan@bladerunner.io>");
MODULE_DESCRIPTION("List tasks");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");



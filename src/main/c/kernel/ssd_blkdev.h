#ifndef SSD_BLKDEV_IOCTL_H_
#define SSD_BLKDEV_IOCTL_H_

struct ssd_move_page {
	unsigned long old_ppn;
	unsigned long new_ppn;
};

#define SSD_BLKDEV_MAGIC	'x'

#define SSD_BLKDEV_REGISTER_APP	_IO(SSD_BLKDEV_MAGIC, 0)
#define SSD_BLKDEV_GET_REQ_SIZE	_IOR(SSD_BLKDEV_MAGIC, 1, unsigned long)
#define SSD_BLKDEV_GET_LBN		_IOR(SSD_BLKDEV_MAGIC, 2, unsigned long)
#define SSD_BLKDEV_SET_PPN		_IOW(SSD_BLKDEV_MAGIC, 3, unsigned long)
#define SSD_BLKDEV_MOVE_PAGE	_IOW(SSD_BLKDEV_MAGIC, 4, struct ssd_move_page)

#define SSD_REQUEST_SIZE	8

/*
 * sector_request_map: Holds the mapping information. Used to
 * communicate with the user-space.
 *
 * lba: Logical Block Address- Supplied by FS layer
 * psn: Physical sector number- Obtained from mapping table
 * dir: Direction: 1-Write; 0-Read
 */
struct sector_request_map {
	int dir;
	unsigned int num_sectors;
	unsigned long start_lba;
	unsigned long psn[SSD_REQUEST_SIZE];
	void *request_buff;
};

#endif /* SSD_BLKDEV_IOCTL_H_ */

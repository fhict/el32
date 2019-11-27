/*
 * de volgende code laat het ledje op de gamepad rondspinnen:
*/

#include <libusb-1.0/libusb.h>
#include <stdio.h>

// Endpoint number
#define EP 0x1

int main(int argc, char *argv[]) {

	libusb_device_handle *h;
	
	unsigned char data[] = { 1, 3, 0x0d };
	int error, transferred;

	libusb_init(NULL);
	h = libusb_open_device_with_vid_pid(NULL, 0x045e, 0x028e);

	if (h == NULL) {
		fprintf(stderr, "Failed to open device\n");
		return 1;
	}

	if (libusb_kernel_driver_active(h, 0) == 1) {

		if (libusb_detach_kernel_driver(h, 0) != 0) {
			fprintf(stderr, "Kernel detach error\n");
			return 1;
		}

	}

	if (libusb_claim_interface(h, 0) != 0) {
		fprintf(stderr, "Claim error\n");
		return 1;
	} 

	// Your endpoint number might be different. Check lsusb output
	if ((error = libusb_interrupt_transfer(h, EP, data, sizeof data, &transferred, 0)) != 0) {
		fprintf(stderr, "Transfer failed: %d\n", error);
		return 1;
	}

	// Properly closing libusb
	libusb_release_interface(h, 0);
	libusb_close(h);
	libusb_exit(NULL);

	return 0;
}


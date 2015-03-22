#! /usr/bin/env python3

import logging.config
import sys
import multiprocessing as mp
import os

import xbx.config as xbxc
import xbx.build as xbxb
import xbx.data as xbxd



def main():
    logging.config.fileConfig("logging.ini")
    config = xbxc.Config("config.ini")

    db = xbxd.Database(config)

    bs = xbxb.BuildSession(config, db)
    bs.buildall()




if __name__ == "__main__":
    main()
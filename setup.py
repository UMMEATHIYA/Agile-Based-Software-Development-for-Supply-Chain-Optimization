from distutils.core import setup
from Cython.Build import cythonize
import os

setup(
    ext_modules = cythonize("optimization_module.pyx"),
    include_dirs=[os.path.join(os.environ['CXX_INCLUDE'], 'cpp')],
    libraries=["optimization_module"],
)

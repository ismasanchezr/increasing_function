from setuptools import setup

setup(
    name="find_square",
    version="1.0",
    description="Python wrapper for a C++ find_square function",
    author="Ismael Sánchez Relaño",
    packages=["find_square"],
    package_data={"find_square": ["_find_square.so"]},
    include_package_data=True,
    zip_safe=False,
)

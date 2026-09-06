class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity cannot be negative")
        self._capacity = capacity
        self.cookies = 0

    def __str__(self):
        return '🍪' * self.cookies

    def deposit(self, n):
        if not isinstance(n, int) or n < 0 or self._capacity < (self.cookies + n):
            raise ValueError("Invalid deposit number")
        self.cookies += n

    def withdraw(self, n):
        if not isinstance(n, int) or n < 0 or self.cookies < n:
            raise ValueError("Invalid withdraw number")
        self.cookies -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self.cookies

def permute(original, table):
    return ''.join(original[i - 1] for i in table)

def generate_subkeys(key):
    # PC-1 Permutation
    pc1 = [57, 49, 41, 33, 25, 17, 9, 1,
           58, 50, 42, 34, 26, 18, 10, 2,
           59, 51, 43, 35, 27, 19, 11, 3,
           60, 52, 44, 36, 63, 55, 47, 39,
           31, 23, 15, 7, 62, 54, 46, 38,
           30, 22, 14, 6, 61, 53, 45, 37,
           29, 21, 13, 5, 28, 20, 12, 4]
    
    key = permute(key, pc1)
    c = key[:28]
    d = key[28:]
    
    subkeys = []
    shifts = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]
    
    for shift in shifts:
        c = c[shift:] + c[:shift]
        d = d[shift:] + d[:shift]
        cd = c + d
        
        # PC-2 Permutation
        pc2 = [14, 17, 11, 24, 1, 5, 3, 28,
               15, 6, 21, 10, 23, 19, 12, 4,
               26, 8, 16, 7, 27, 20, 13, 2,
               41, 52, 31, 37, 47, 55, 30, 40,
               51, 45, 33, 48, 44, 49, 39, 56,
               34, 53, 46, 42, 50, 36, 29, 32]
        
        subkey = permute(cd, pc2)
        subkeys.append(subkey)
    
    return subkeys

def initial_permutation(text):
    # IP Permutation
    ip = [58, 50, 42, 34, 26, 18, 10, 2,
          60, 52, 44, 36, 28, 20, 12, 4,
          62, 54, 46, 38, 30, 22, 14, 6,
          64, 56, 48, 40, 32, 24, 16, 8,
          57, 49, 41, 33, 25, 17, 9, 1,
          59, 51, 43, 35, 27, 19, 11, 3,
          61, 53, 45, 37, 29, 21, 13, 5,
          63, 55, 47, 39, 31, 23, 15, 7]
    
    return permute(text, ip)

def expansion(text):
    # Expansion Permutation
    exp = [32, 1, 2, 3, 4, 5, 4, 5,
           6, 7, 8, 9, 8, 9, 10, 11,
           12, 13, 12, 13, 14, 15, 16, 17,
           16, 17, 18, 19, 20, 21, 20, 21,
           22, 23, 24, 25, 24, 25, 26, 27,
           28, 29, 28, 29, 30, 31, 32, 1]
    
    return permute(text, exp)

def substitution(text):
    # S-Box Tables
    # S-Box Tables
    s_boxes = [
    [
        [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
        [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
        [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
        [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
    ],
    [
        [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
        [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
        [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
        [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9],
    ],
    [
        [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
        [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
        [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
        [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12],
    ],
    [
        [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
        [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
        [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
        [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14],
    ],
    [
        [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
        [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
        [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
        [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3],
    ],
    [
        [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
        [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
        [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
        [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13],
    ],
    [
        [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
        [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
        [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
        [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12],
    ],
    [
        [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
        [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
        [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
        [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11],
    ],
]

    
    result = ''
    for i in range(8):
        row = int(text[i * 6] + text[i * 6 + 5], 2)
        col = int(text[i * 6 + 1:i * 6 + 5], 2)
        value = s_boxes[i][row][col]
        result += format(value, '04b')
    
    return result

def permutation(text):
    # P Permutation
    p = [16, 7, 20, 21, 29, 12, 28, 17,
         1, 15, 23, 26, 5, 18, 31, 10,
         2, 8, 24, 14, 32, 27, 3, 9,
         19, 13, 30, 6, 22, 11, 4, 25]
    
    return permute(text, p)

def final_permutation(text):
    # IP-1 Permutation
    ip_inv = [40, 8, 48, 16, 56, 24, 64, 32,
              39, 7, 47, 15, 55, 23, 63, 31,
              38, 6, 46, 14, 54, 22, 62, 30,
              37, 5, 45, 13, 53, 21, 61, 29,
              36, 4, 44, 12, 52, 20, 60, 28,
              35, 3, 43, 11, 51, 19, 59, 27,
              34, 2, 42, 10, 50, 18, 58, 26,
              33, 1, 41, 9, 49, 17, 57, 25]
    
    return permute(text, ip_inv)

def binary_to_ascii(binary_str):
    return ''.join(chr(int(binary_str[i:i+8], 2)) for i in range(0, len(binary_str), 8))

def des_encrypt_block(block, subkeys):
    # Initial Permutation
    block = initial_permutation(block)
    
    # Split into left and right halves
    left, right = block[:32], block[32:]
    
    for i in range(16):
        # Expansion
        expanded_right = expansion(right)
        
        # XOR with subkey
        key_xor = bin(int(expanded_right, 2) ^ int(subkeys[i], 2))[2:].zfill(48)
        
        # Substitution
        substituted = substitution(key_xor)
        
        # Permutation
        permuted = permutation(substituted)
        
        # XOR with left half
        new_right = bin(int(left, 2) ^ int(permuted, 2))[2:].zfill(32)
        
        # Update left and right for the next round
        left, right = right, new_right
    
    # Final permutation and combine
    encrypted_block = final_permutation(right + left)
    
    return encrypted_block

def des_encrypt(plain_text, key):
    # Padding if needed
    if len(plain_text) % 8 != 0:
        plain_text += ' ' * (8 - len(plain_text) % 8)
    
    # Convert key to binary
    key_binary = ''.join(format(ord(c), '08b') for c in key)
    
    # Generate subkeys
    subkeys = generate_subkeys(key_binary)
    
    # Encrypt each block
    cipher_text = ''
    for i in range(0, len(plain_text), 8):
        block = ''.join(format(ord(c), '08b') for c in plain_text[i:i+8])
        encrypted_block = des_encrypt_block(block, subkeys)
        cipher_text += binary_to_ascii(encrypted_block)
    
    return cipher_text


def des_decrypt_block(block, subkeys):
    # Initial Permutation
    block = initial_permutation(block)
    
    # Split into left and right halves
    left, right = block[:32], block[32:]
    
    for i in range(15, -1, -1):  # Reverse order of subkeys
        # Expansion
        expanded_right = expansion(right)
        
        # XOR with subkey
        key_xor = bin(int(expanded_right, 2) ^ int(subkeys[i], 2))[2:].zfill(48)
        
        # Substitution
        substituted = substitution(key_xor)
        
        # Permutation
        permuted = permutation(substituted)
        
        # XOR with left half
        new_right = bin(int(left, 2) ^ int(permuted, 2))[2:].zfill(32)
        
        # Update left and right for the next round
        left, right = right, new_right
    
    # Final permutation and combine
    decrypted_block = final_permutation(right + left)
    
    return decrypted_block

def des_decrypt(cipher_text, key):
    # Convert key to binary
    key_binary = ''.join(format(ord(c), '08b') for c in key)
    
    # Generate subkeys
    subkeys = generate_subkeys(key_binary)
    
    # Decrypt each block
    decrypted_text = ''
    for i in range(0, len(cipher_text), 8):
        block = ''.join(format(ord(c), '08b') for c in cipher_text[i:i+8])
        decrypted_block = des_decrypt_block(block, subkeys)
        decrypted_text += binary_to_ascii(decrypted_block)
    
    return decrypted_text
# Example usage
plain_text = "Hello123zxcv"
key = "MyKey123"

# Encryption
cipher_text = des_encrypt(plain_text, key)
print("Cipher Text:", cipher_text)

# Decryption
decrypted_text = des_decrypt(cipher_text, key)
print("Decrypted Text:", decrypted_text)
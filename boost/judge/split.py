import os

def split_file(filename, parts):
    file_size = os.path.getsize(filename)
    part_size = file_size // parts
    with open(filename, 'rb') as f:
        for i in range(parts):
            with open(f'{filename}.part{i}', 'wb') as part_file:
                part_file.write(f.read(part_size))
        # 最後のパートに残りのデータを追加
        with open(f'{filename}.part{parts-1}', 'ab') as part_file:
            part_file.write(f.read())

# 使用例
split_file('./pi-10oku.txt', 10)
